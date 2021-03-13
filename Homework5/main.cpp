#include <iostream>
#include <functional>
#include "function.hpp"

using namespace std;
using namespace My_Arrey_Function;
using Print_Ptr = void(*)(int*, int);
 
const int size = 10;                 
int arrey[size] = {1, 0, 1, 1, 0, 0, 1, 0, 0, 1};       
int arrey_2[8] {};
int arrey_3[8] = {1, 1, 1, 2, 0, 0, 1, 4};

int main()
{
    Print_Ptr function_print = Print_Arrey;

    // homework 1
    {
    std::cout << "Homework 1: " << "\n";
    std::cout << "Original array: " << "\n";

    function_print(arrey, size);
 
    std::function<void(int*, int)> replase_0_to_1 = Replase_Arrey_0_to_1;
    replase_0_to_1(arrey, size);

    std::cout << "Modified array: " << "\n";

    function_print(arrey, size);

    std::cout << "\n";
    }

    // homework 2
    {
    std::cout << "Homework 2: " << "\n";

    std::function<void(int*, int)> fill_arrey = Fills_the_Array;

    fill_arrey(arrey_2,8);
    
    function_print(arrey_2, 8);

    std::cout << "\n";
    }

    // homework 3
    {
    std::cout << "Homework 3: " << "\n";
    int res;
    std::function<int(int*, int)> compare = Compare_Arrey;
    res = compare(arrey_3, 8);
    std::cout << res << " ";
    if ((res) == true){
        std::cout << "true" << "\n";
    } else {
        std::cout << "false" << "\n";
        }
    std::cout << "\n";    
    }

    // homework 4
    {
    std::cout << "Homework 4: " << "\n";
    std::cout << "Original array: " << "\n";

    function_print(arrey_2, 8);

    int drift = -3;  // сдвиг

    std::function<void(int*, int, int)> shift_arr = Shift_Arrey;
    shift_arr(arrey_2, drift, 8);

    std::cout << "Modified array: " << "\n";

    function_print(arrey_2, 8);
    }

    // homework 6
    // all functions are called via pointers

    return (0);
}
