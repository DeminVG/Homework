#include <iostream>

int main() {

    // homework 1
    {
    double a = 10, b = 0, sum;

    std::string res;

    sum = a + b;

    if (sum > 20) {
        res = "false\n";
    } else if (sum >= 10) {
        res = "true\n";
    } else {
        res = "false\n";
    }

    std::cout << res;
    }

    // homework 2
    {
    int a = 11;

    std::string res;    
    if (a == 1 || a == 2){
        std::cout << a <<  " prime number\n";
    } else{
        for(int i = (a - 1); i > 0; i--) {
                if ((a % i) == 0) {
                    std::cout << a << " is not a prime number\n";
                    break;
                }
                if (i == 2) {
                    std::cout << a <<  " prime number\n";
                    break;
                }            
            }
        }   
     std::cout << "\n";
    }

    // homework 3
    {
        int a = 5, b = 5;
    
        std::string res;
    
        if (a == 10 || b ==10 || (a + b) == 10) {
            res = "true\n";
        } else {
            res = "false\n";
        }
        std::cout << res;
        }
    // homework 4
    {
        int year = 900;
    
        if ((year % 400) == 0) {
            std::cout << year << " high-grade year \n";
        } else if ((year % 100) == 0) {
                std::cout << year << " is not high-grade year \n";
            } else if ((year % 4) == 0) {
                    std::cout << year << " high-grade year \n";       
                } else {
                        std::cout << year << " is not high-grade year \n";
                    }          
    } 
}