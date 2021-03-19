#include <iostream>

int main()
{
    int c;
    bool in_num_f = false;
    while ((c = getchar()) != -1){
        if ('0' <= c && c <= '9') {
            if (!in_num_f && c == '0'){
                while ((c = getchar()) == '0') {}
                if (c == -1) {
                    std::cout << '0';
                    break;
                }
                if ('1' > c || c > '9') {
                    std::cout << '0' << char(c);
                    in_num_f = false;
                    continue;
                }
            }
            std::cout << char(c);
            in_num_f = true;
        } else {
            std::cout << char(c);
            in_num_f = false;
        }
    }
}
