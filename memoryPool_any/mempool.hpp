#ifndef __MEMPOOL_HPP_
#define __MEMPOOL_HPP_

#include <iostream>
#include <cstdio>

#define MAX_HEAP (20*(1<<20))  /* 20 MB */

class MemPool {
public:
    MemPool():mem_heap((char*)malloc(MAX_HEAP)), mem_brk(mem_heap), mem_max_brk(mem_heap + MAX_HEAP) {}
    void *sbrk(int incr) {
        char *old_brk = mem_brk;
        if ( incr < 0 || mem_brk + incr > mem_max_brk ) {
            fprintf(stderr, "ERROR: mem_sbrk failed. Ran out of memory...\n");
            return (void*)-1;  
        }
        mem_brk += incr;
        return (void*) old_brk;
    }

private:
    char *mem_heap;
    char *mem_brk;
    char *mem_max_brk;
};


#endif