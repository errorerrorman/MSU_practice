#include <string>
#include <cmath>

#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"



int main(int argc, char **argv)
{
    numbers::complex C(argv[1]);
    double R = std::stod(argv[2]);
    int N = std::stoi(argv[3]);
    std::vector<std::string> args;
    for (int i = 4; argv[i]; ++i) {
        args.push_back(argv[i]);
    }

    numbers::complex I;
    numbers::complex v(std::cos(2 * M_PI / N), std::sin(2 * M_PI / N)), z = 1;
   

    for (int i = 0 ; i < N; ++i) {
        I += eval(args, C + z * R) * z * (v - 1);
        z *= v;
    }
    
    std::cout << I.to_string() << std::endl;
}
