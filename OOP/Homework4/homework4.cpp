#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    // Lesson 2
    cout << "Lesson 2" << endl;
    
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
