#include <iostream>
#include <vector>
#include <cstdint>


void process(const std::vector<uint64_t>& v_source, std::vector<uint64_t>& v_dest, size_t step)
{
    if (v_source.empty() || v_dest.empty()) {
        return;
    }
    std::vector<uint64_t>::const_iterator source = v_source.begin();
    std::vector<uint64_t>::iterator dest = v_dest.end() - 1;
    while (source < v_source.end() && dest >= v_dest.begin()) {
        *dest += *source;
        source += step;
        --dest;
    }
}
