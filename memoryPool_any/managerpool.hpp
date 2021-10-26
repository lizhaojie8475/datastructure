#ifndef _MANAGER_HPP_
#define _MANAGER_HPP_

#include "mempool.hpp"
#include <iostream>
#include <cstdlib>

#define WSIZE       4       /* Word and header/footer size (bytes) */ //line:vm:mm:beginconst
#define DSIZE       8       /* Double word size (bytes) */
#define CHUNKSIZE  (1<<12)  /* Extend heap by this amount (bytes) */  //line:vm:mm:endconst 

#define MAX(x, y) ((x) > (y)? (x) : (y)) 

/* Pack a size and allocated bit into a word */
#define PACK(size, alloc)  ((size) | (alloc)) //line:vm:mm:pack

/* Read and write a word at address p */
#define GET(p)       (*(unsigned int *)(p))            //line:vm:mm:get
#define PUT(p, val)  (*(unsigned int *)(p) = (val))    //line:vm:mm:put

/* Read the size and allocated fields from address p */
#define GET_SIZE(p)  (GET(p) & ~0x7)                   //line:vm:mm:getsize
#define GET_ALLOC(p) (GET(p) & 0x1)                    //line:vm:mm:getalloc

/* Given block ptr bp, compute address of its header and footer */
#define HDRP(bp)       ((char *)(bp) - WSIZE)                      //line:vm:mm:hdrp
#define FTRP(bp)       ((char *)(bp) + GET_SIZE(HDRP(bp)) - DSIZE) //line:vm:mm:ftrp

/* Given block ptr bp, compute address of next and previous blocks */
#define NEXT_BLKP(bp)  ((char *)(bp) + GET_SIZE(((char *)(bp) - WSIZE))) //line:vm:mm:nextblkp
#define PREV_BLKP(bp)  ((char *)(bp) - GET_SIZE(((char *)(bp) - DSIZE))) //line:vm:mm:prevblkp

struct MemoryBlockHeader {
    int size;
    
};

class ManagerPool {
public:
    static ManagerPool &GetInstance() {
        static ManagerPool manp;
        return manp;
    }

    void *mm_malloc(size_t size) {
        size_t asize;      /* Adjusted block size */
        size_t extendsize; /* Amount to extend heap if no fit */
        char *bp;      

        /* $begin mmmalloc */
        /* Ignore spurious requests */
        if (size == 0)
            return nullptr;

        /* Adjust block size to include overhead and alignment reqs. */
        if (size <= DSIZE)                                          //line:vm:mm:sizeadjust1
            asize = 2*DSIZE;                                        //line:vm:mm:sizeadjust2
        else
            asize = DSIZE * ((size + (DSIZE) + (DSIZE-1)) / DSIZE); //line:vm:mm:sizeadjust3

        /* Search the free list for a fit */
        if ((bp = (char*)find_fit(asize)) != nullptr) {  //line:vm:mm:findfitcall
            place(bp, asize);                  //line:vm:mm:findfitplace
            return bp;
        }

        /* No fit found. Get more memory and place the block */
        extendsize = MAX(asize,CHUNKSIZE);                 //line:vm:mm:growheap1
        if ((bp = (char*)extend_heap(extendsize/WSIZE)) == nullptr)  
            return nullptr;                                  //line:vm:mm:growheap2
        place(bp, asize);                                 //line:vm:mm:growheap3
        return bp;
    } 
    void mm_free(void *bp) {
        if (bp == 0) 
            return;

        size_t size = GET_SIZE(HDRP(bp));

        PUT(HDRP(bp), PACK(size, 0));
        PUT(FTRP(bp), PACK(size, 0));
        coalesce(bp);
    }

    void printblock(void *bp); 
    void checkheap(int verbose);
    void checkblock(void *bp);    

private:
    ManagerPool() {
        if ( (heap_listp = (char*)mp.sbrk(4 * WSIZE)) == (char*)-1)
            throw std::runtime_error("sbrk failed");

        // 头部初始化时，每个块的最小单位是8字节 = header4 + footer4
        PUT(heap_listp, 0);                          /* Alignment padding */
        PUT(heap_listp + (1*WSIZE), PACK(DSIZE, 1)); /* Prologue header */ 
        PUT(heap_listp + (2*WSIZE), PACK(DSIZE, 1)); /* Prologue footer */ 
        PUT(heap_listp + (3*WSIZE), PACK(0, 1));     /* Epilogue header */
        heap_listp += (2*WSIZE);                     //line:vm:mm:endinit  

        extend_heap(CHUNKSIZE / WSIZE);
        
    }
    void *extend_heap(size_t words) {
        char *bp;
        size_t size;

        /* Allocate an even number of words to maintain alignment */
        size = (words % 2) ? (words+1) * WSIZE : words * WSIZE; //line:vm:mm:beginextend
        if ((long)(bp = (char*)mp.sbrk(size)) == -1)  
            return nullptr;                                        //line:vm:mm:endextend
        // 这里size的大小没有算上header，是因为
        /* Initialize free block header/footer and the epilogue header */
        PUT(HDRP(bp), PACK(size, 0));         /* Free block header */   
        PUT(FTRP(bp), PACK(size, 0));         /* Free block footer */   
        PUT(HDRP(NEXT_BLKP(bp)), PACK(0, 1)); /* New epilogue header */  // 这个尾部块，之所以只保留头部，就是为了方便在尾部扩展新的块。

        /* Coalesce if the previous block was free */
        return coalesce(bp);                                          //line:vm:mm:returnblock
    }
    void *coalesce(void *bp) {
        size_t prev_alloc = GET_ALLOC(FTRP(PREV_BLKP(bp)));
        size_t next_alloc = GET_ALLOC(HDRP(NEXT_BLKP(bp)));
        size_t size = GET_SIZE(HDRP(bp));

        if (prev_alloc && next_alloc) {            /* Case 1 */
            return bp;
        }

        else if (prev_alloc && !next_alloc) {      /* Case 2 */
            size += GET_SIZE(HDRP(NEXT_BLKP(bp)));
            PUT(HDRP(bp), PACK(size, 0));
            PUT(FTRP(bp), PACK(size,0));
        }

        else if (!prev_alloc && next_alloc) {      /* Case 3 */
            size += GET_SIZE(HDRP(PREV_BLKP(bp)));
            PUT(FTRP(bp), PACK(size, 0));
            PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
            bp = PREV_BLKP(bp);
        }

        else {                                     /* Case 4 */
            size += GET_SIZE(HDRP(PREV_BLKP(bp))) + GET_SIZE(FTRP(NEXT_BLKP(bp)));
            PUT(HDRP(PREV_BLKP(bp)), PACK(size, 0));
            PUT(FTRP(NEXT_BLKP(bp)), PACK(size, 0));
            bp = PREV_BLKP(bp);
        }
        return bp;
    }
    void *find_fit(size_t asize) {
        /* First-fit search */
        void *bp;

        for (bp = heap_listp; GET_SIZE(HDRP(bp)) > 0; bp = NEXT_BLKP(bp)) {
            if (!GET_ALLOC(HDRP(bp)) && (asize <= GET_SIZE(HDRP(bp)))) {
                return bp;
            }
        }
        return nullptr; /* No fit */
    }

    void place(void *bp, size_t asize) {
        size_t csize = GET_SIZE(HDRP(bp));   

        if ((csize - asize) >= (2*DSIZE)) { 
            PUT(HDRP(bp), PACK(asize, 1));
            PUT(FTRP(bp), PACK(asize, 1));
            bp = NEXT_BLKP(bp);
            PUT(HDRP(bp), PACK(csize-asize, 0));
            PUT(FTRP(bp), PACK(csize-asize, 0));
        }
        else { 
            PUT(HDRP(bp), PACK(csize, 1));
            PUT(FTRP(bp), PACK(csize, 1));
        }
    }

    char *heap_listp;
    MemPool mp;
};

void* operator new(size_t s) {
    return ManagerPool::GetInstance().mm_malloc(s);
}

void operator delete(void* p) {
    return ManagerPool::GetInstance().mm_free(p);
}

void* operator new[](size_t nSize) {
    return ManagerPool::GetInstance().mm_malloc(nSize);
}

void operator delete[](void* p) {
    return ManagerPool::GetInstance().mm_free(p);
}

#endif