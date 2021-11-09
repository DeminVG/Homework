#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

template<typename T>
void PrintUnique(T begin, T end)
{   
    for (T ptr1 = begin; ptr1 != end; ++ptr1)
    {
        T ptr2;
        for (ptr2 = begin; ptr2 != ptr1; ++ptr2) {
            if (*ptr1 == *ptr2) {
                break;
            }
        }
        if (ptr1 == ptr2) {
            cout << *ptr1 << " ";
        }
    }
    cout << endl;
}

int main()
{
    // Lesson 1
    cout << "Lesson 1:" << endl;
    vector<string> vec_str;
    string str = " ";

    cout << "Enter string: ";
    do {
        cin >> str;
        vec_str.push_back(str);
    } while (cin.get() != '\n');
   
    PrintUnique(vec_str.begin(), vec_str.end());
    
    vector<int> vec_int;
    int num = 0;

    cout << "Enter numbers: ";
    do {
        cin >> num;
        vec_int.push_back(num);
    } while (cin.get() != '\n');

    PrintUnique(vec_int.begin(), vec_int.end());

    list<int> MyList;

    cout << "Enter numbers: ";
    do {
        cin >> num;
        MyList.push_back(num);
    } while (cin.get() != '\n');

    PrintUnique(MyList.begin(), MyList.end());
       
    return 0;
}