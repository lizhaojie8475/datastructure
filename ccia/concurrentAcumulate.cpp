#include <iostream>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <thread>
#include <vector>

using namespace std;

template<typename Iterator, typename T>
struct accumulate_ref{
    void operator () (Iterator first, Iterator last, T&result) {
        result = accumulate(first, last, result);
    }
};

template< typename Iterator, typename T>
T accumulate_parallel( Iterator first, Iterator last, T init) {
    typedef typename iterator_traits<Iterator>::difference_type diff_type;
    diff_type length = distance(first, last);

    if(!length)
        return init;

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = (length + min_per_thread - 1) / min_per_thread;   // 向上去整的做法，不足一个min_per_thread就算一个，刚好一个也是一个，不足两个就算两个。
    unsigned long const hardware_threads = std::thread::hardware_concurrency();
    unsigned long const num_threads = std::min(hardware_threads != 0 ? hardware_threads : 2, max_threads);
    unsigned long const block_size = length / num_threads;

    vector<T> results(num_threads);
    vector<thread> threads(num_threads - 1);  // 最后一部分不足一个block_size，所以循环外单独处理
    Iterator block_start = first;
    for (unsigned long i = 0; i < num_threads - 1; i++) {
        Iterator block_end = first;
        std::advance(block_end, block_size);
        threads[i] = thread(accumulate_ref<Iterator, T>(), block_start, block_end, ref(results[i]));
        block_start = block_end;
    }
    accumulate_ref<Iterator, T>() (block_start, last, results[num_threads - 1]);
    std::for_each(threads.begin(), threads.end(), std::mem_fn(&std::thread::join));
    
    return std::accumulate(results.begin(), results.end(), init);
}

int main() {
    int a;
    vector<int> v(1000, 1);
    int sum = accumulate_parallel(v.begin(), v.end(), 0);
    cout << sum << endl;;
}