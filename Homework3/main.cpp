#include <iostream>

extern int A, B, C, D;

int main(){

    // homework 1
    {
        int a = 1, b = 2, c = 3, d = 4;
        float res1;

        res1 = static_cast<float>(a) * (static_cast<float>(b) + (static_cast<float>(c) / static_cast<float>(d)));
        std::cout << "result1 = " << res1 << "\n";
    }

    // homework 2
    {
        int a = 23;

        int res2 = ((a <= 21) ? (21 - a) : (a - 21) * 2 );   //  если a не больше 21, то 21 - а , иначе (21 - а) * 2
        std::cout << "result2 = " << res2 << "\n";
    }

    // homework 3
    {
        float res3;

        res3 = static_cast<float>(A) * (static_cast<float>(B) + (static_cast<float>(C) / static_cast<float>(D)));
        std::cout << "result3 = " << res3 << "\n";
    }

    // homework 4
    {
        int cub_size = 7;
        int arrey[7][7][7]{};

        arrey[cub_size/2][cub_size/2][cub_size/2] = 123;    // for control

        int* ptr = &arrey[0][0][0];
        std::cout << "Array length: " << (sizeof(arrey) / sizeof(int)) << "\n";
        std::cout << "Array center: " << ((sizeof(arrey) / sizeof(int))/2) << "\n";
        std::cout << "Value of the central element of array: " << *(ptr + ((sizeof(arrey) / sizeof(int))/2)) << "\n";
    }
} 