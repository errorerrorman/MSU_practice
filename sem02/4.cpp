#include <iostream>

void one_out(int c)
{
    if (c == '#') {                                                                
        std::cout << "##1#";                                                            
    } else if (c != EOF) {                                                         
        std::cout << char(c);                                                      
    } 
}

int main()
{
    int c_prev = EOF, c;
    while (1) {
        if ((c = getchar()) == EOF) {
            one_out(c_prev);
            break;
        } else {
            if (c == c_prev) {
                int count = 2;
                while ((c = getchar()) == c_prev) {
                    ++count;
                }
                if (count > 4 || c_prev == '#') {
                    std::cout << '#' << char(c_prev) << std::hex << count << '#';
                } else {
                    for (int i = 0; i < count; ++i) {
                        std::cout << char(c_prev);
                    }
                }
            } else {
                one_out(c_prev);
            }
            c_prev = c;
        }
    }
}
