#include <iostream>

#define IN_RANGE(num, max) (((num) >= 0) && ((num) < max))

#define GET_ELEM(arr, x, y) *((*(arr + y)) + x)

#define ARREY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

int main() {

    // Lesson 1

    std::cout << "Lesson 1:\n";
    int i = 100;
    if (IN_RANGE(i, 100)) {
        std::cout << "Number " << i << " in range.\n";
        
    } else {
        std::cout << "Number " << i << " is not in range.\n";
    }
    std::cout << "\n";

    // Lesson 2
    
    std::cout << "Lesson 2:\n";
    int** matrix = new int*[3]{};
    matrix[0] = new int[5]{};
    matrix[1] = new int[5]{};
    matrix[2] = new int[5]{};

    matrix[2][4] = 32;

    std::cout << "Array element: " << GET_ELEM(matrix, 4, 2) << "\n";
    std::cout << "\n";

    // Lesson 3

    std::cout << "Lesson 3:\n";

    int arrey[10]{};
    std::cout << "Array size: " << ARREY_SIZE(arrey) << "\n";
    std::cout << "\n";

    return 0;
}