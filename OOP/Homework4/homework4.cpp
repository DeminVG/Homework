#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include "ArrayInt.h"

using namespace std;

int main()
{
    using namespace std;
     // Lesson 1
    {
        cout << "Lesson 1:\n";
        ArrayInt arr;
        arr.push_back(2);
        arr.push_back(14);
        arr.push_back(5);
        arr.push_back(71);
        arr.push_back(4);
        arr.push_back(13);
        arr.PrintArr();

        arr.pop_back();
        arr.PrintArr();

        arr.pop_front();
        arr.PrintArr();
    }

    // Lesson 2
    cout << "\nLesson 2" << endl;
    
    vector<int> arr{12, 4, 56, 78, 4, 4, 12};
    
    vector<int>::iterator it;
    it = arr. begin() ;
    
    sort(arr.begin(), arr.end()) ;
    
    int num = 0;
    
    for(int i = 0; i < arr.size(); i++){
        if(*(it + i) != *(it + i +1)) {
            num++;
        }
    } 
    cout << "В векторе "<< num << " различных чисел(числа)." << endl;
    
    return 0;
}