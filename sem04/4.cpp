#include <vector>
#include <algorithm>
#include <iomanip>
#include <iostream>

int main()
{
    std::vector<double> v;
    double tmp;
    while (std::cin >> tmp){
        v.push_back(tmp);
    }
    size_t d_len = v.size() / 10;
    v.erase(v.begin(), v.begin() + d_len);
    v.erase(v.end() - d_len, v.end());
    std::sort(v.begin(), v.end());
    d_len = v.size() / 10;
    v.erase(v.begin(), v.begin() + d_len);
    v.erase(v.end() - d_len, v.end());

    class avg{
        double sum{};
        int n{};
    public:
        void operator ()(double x){
            ++n;
            sum += x;
        }

        double get_avg(){
            if (n) {
                return sum / n;
            }
            return 0;
        }
    };

    std::cout << std::fixed << std::setprecision(10) <<
        std::for_each(v.begin(), v.end(), avg()).get_avg();    

}
