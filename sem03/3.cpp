#include <map>
#include <vector>
#include <functional>
#include <iostream>
#include <sstream>
#include <cmath>
#include <iomanip>

namespace numbers{
    complex eval(const std::vector<std::string> &args, const complex &z){

        complex_stack s;
        
        static std::map <std::string, std::function<void()>> operations;
        operations["z"] = [&s, z] {
            s = s << z;
        };

        operations["+"] = [&s] {
            complex tmp = +s;
            s = ~s;
            tmp += +s;
            s = ~s << tmp;
        };

        operations["-"] = [&s] {                                                                    
            complex tmp = +s;                                                                       
            s = ~s;                                                                                 
            tmp = +s - tmp;                                                                              
            s = ~s << tmp;                                                                        
        };

        operations["*"] = [&s] {                                                                    
            complex tmp = +s;                                                                       
            s = ~s;                                                                                 
            tmp *= +s;                                                                              
            s = ~s << tmp;                                                                        
        };

        operations["/"] = [&s] {                                                                    
            complex tmp = +s;                                                                       
            s = ~s;                                                                                 
            tmp = +s / tmp;                                                                              
            s = ~s << tmp;                                                                        
        };

        operations["!"] = [&s] {s = s << +s;};

        operations[";"] = [&s] {s = ~s;}; 
        
        operations["~"] = [&s] {
            complex tmp = +s;
            s = ~s << ~tmp;
        };

        operations["#"] = [&s] {
            complex tmp = +s;
            s = ~s << -tmp;
        };

        for (const std::string &str : args) {
            if (str[0] == '(') {
                s = s << complex(str);
            } else {
                operations[str]();
            }
        };

        return +s;
    }
}
