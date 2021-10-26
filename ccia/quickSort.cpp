#include <iostream>
#include <list>


template<typename T>
std::list<T> sequential_quick_sort(std::list<T> input) {
    if(input.empty()) {
        return input;
    }
    std::list<T> result;
    result.splice(result.begin(), input, input.begin());    // 将input中的第一个数据move到result的头部，注意splice会将数据从input中移除。
    T const& pivot = *result.begin();
    auto divide_point = std::partition(input.begin(), input.end(), [pivot](T const& t){return t < pivot;}); // partition会将迭代器范围内的元素调用函数对象，返回为true的在前半部分，返回为false的在后半部分。
                                                                                                        // 返回迭代器指向后半部分的开头
    std::list<T> lower_part;
    lower_part.splice(lower_part.begin(), input, input.begin(), divide_point);                          // 将前半部分move到一个新的容器，这样input剩余的部分自动成为后半部分。
    auto new_lower(
        sequential_quick_sort(std::move(lower_part)));                                                  // 
    auto new_higher(
        sequential_quick_sort(std::move(input)));
    result.splice(result.end(), new_higher);
    // Ussing synchronization of operations to simplify code
    result.splice(result.begin(), new_lower);
    return result;
}

template<typename Iterator>
void parallel_quick_sort(Iterator first, Iterator last) {
    if(first == last || first + 1 == last)
        return;
    int const& pivot = *first;
    auto divide_point = std::stable_partition(first, last, [=](int const& t){return t < pivot;});
    auto lower = async(std::launch::async, &parallel_quick_sort<Iterator>, first, divide_point);
    parallel_quick_sort(divide_point + 1, last);  
    lower.get();
}


