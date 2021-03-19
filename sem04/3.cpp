#include <vector>
#include <algorithm>
#include <iostream>

void process(const std::vector<int>& v1, std::vector<int>& v2)
{
    if (v1.empty() || v2.empty()) {
        return;
    }
    std::vector<int> v = v1;
    std::sort(v.begin(), v.end());
    v.erase(std::unique(v.begin(), v.end()), v.end());

    std::vector<int>::iterator erase_begin = v2.begin(), erase_end = erase_begin;
    int size = v2.end() - v2.begin(), i = 0;

    for (std::vector<int>::iterator it = v.begin(); it < v.end() && i < size;) {
        if (*it >= 0) {
            if (*it == i) {
                ++it;
            } else {
                std::swap(*erase_begin, *erase_end);
                ++erase_begin;
            }
            ++erase_end;
            ++i;
        } else {
            ++it;
        }
    }

    v2.erase(erase_begin, erase_end);
}
