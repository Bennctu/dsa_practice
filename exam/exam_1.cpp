#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>

int main(int argc, char const* argv[]) {
    typedef std::tuple<int, int, double> S_type;
    std::priority_queue<S_type, std::vector<S_type>, std::greater<S_type>>
        max_heap;
    max_heap.push({2, 3, 2.9});
    max_heap.push({5, 2, 1.2});
    std::cout << "top:" << std::get<2>(max_heap.top()) << std::endl;

    return 0;
}
