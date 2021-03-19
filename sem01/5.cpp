#include <iostream>
#include <cstdint>

namespace Hex_tools{
    constexpr uint32_t DEC_A = 10;
    constexpr uint32_t INP_ERR = -1;
    constexpr uint32_t HEX_SIZE = 16;
    constexpr uint32_t OCT_IN_32T = 4;
    constexpr uint32_t OCT_SIZE = 8;

    uint32_t unhex(uint32_t c)
    {
        if ('0' <= c && c <= '9') {
            return c - '0';
        } else if ('a' <= c && c <= 'f') {
            return c - 'a' + DEC_A;
        } else if ('A' <= c && c <= 'F') {
            return c - 'A' + DEC_A;
        }
        return INP_ERR;
    }

    uint32_t gethex()
    {
        uint32_t c1, c2;
        if ((c1 = unhex(getchar())) == INP_ERR || (c2 = unhex(getchar())) == INP_ERR) {
            return INP_ERR;
        }
        return c1 * HEX_SIZE + c2;
    }
}

int main()
{
    bool new_line_f = true;
    uint32_t x = 0;
    int c;
    int octs_count = 0;
    while ((c = getchar()) != EOF){
        if (c == '\n') {
            new_line_f = true;
        } else {
            if (new_line_f) {
                new_line_f = false;
                while ((c = getchar()) != ' ' && c != EOF) {}
                if (c == EOF) {
                    break;
                }
            }
            if (c == ' ') {
                uint32_t tmp = Hex_tools::gethex();
                if (tmp == Hex_tools::INP_ERR) {
                    break;
                }
                x <<= Hex_tools::OCT_SIZE;
                x += tmp;
                ++octs_count;
                if (Hex_tools::OCT_IN_32T == octs_count){
                    std::cout << x << std::endl;
                    octs_count = 0;
                }
            }
        }
    }           
}
