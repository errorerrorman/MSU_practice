#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <stdexcept>

class BinaryNumber{
    std::string num_;
public:
    BinaryNumber() : num_{"0"} {}
    explicit BinaryNumber(const std::string &s) : num_{s} {}
    explicit operator std::string() const{
        return num_; 
    }
    const BinaryNumber &operator++(){
        auto c = num_.end() - 1;
        while (1) {
            if (*c == '0') {
                *c = '1';
                break;
            } else {
                *c = '0';
            }
            if (c == num_.begin()) {
                num_ = "1" + num_;
                break;
            }
            --c;
        }
        return *this;
    }
};

int main()
{
    BinaryNumber x;
    std::cout << std::string(x) << std::endl;
    for (size_t i = 0; i < 10000; ++i) {
        std::cout << std::string(++x) << std::endl;
    }
}
