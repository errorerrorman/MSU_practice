#include <vector>
#include <cstdint>
#include <iostream>

void process(std::vector<int64_t>& v, int64_t threshold)
{
    if (v.empty()){
        return;
    }
    size_t count = 0;
    for (int64_t x : v) {
        if (x >= threshold) {
            ++count;
        }
    }
    size_t n = v.size();
    v.resize(n + count);
    std::vector<int64_t>::iterator il = v.begin() + n, ir = il - 1;
    while (ir >= v.begin()) {
        if (*ir >= threshold) {
            *il = *ir;
            ++il;
        }
        --ir;
    }
}
