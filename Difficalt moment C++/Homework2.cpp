#include <iostream>
#include <vector>
#define SIZE 7

using namespace std;

template <typename T>
void Swap(T** a, T** b) {
    T* temp = *a;
    *a = *b;
    *b = temp;
}

template <typename T>
void SortPointers(vector<T*>& point) {
    int size = point.size();
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (*point[i] > *point[j]) {
                Swap(&point[i], &point[j]);
            }
        }
    }
}

int main()
{
    //Lesson 1

    cout << "Lesson1:" << endl << endl;
    int value1 = 5;
    int value2 = 7;

    int* value1_ptr = &value1;
    int* value2_ptr = &value2;

    cout << "*value1_ptr = " << *value1_ptr << ";  *value2_ptr = " << *value2_ptr << endl;
    cout << "value1 = " << value1 << ";\t  value2 = " << value2 << endl;

    Swap(&value1_ptr, &value2_ptr);

    cout << "*value1_ptr = " << *value1_ptr << ";  *value2_ptr = " << *value2_ptr << endl;
    cout << "value1 = " << value1 << ";\t  value2 = " << value2 << endl;

    //Lesson 2

    cout << "\nLesson2:" << endl << endl;

    double a[SIZE] = { 7.11,8.62,3.14,20.9,98.14,7.25,400.99 };
    vector<double*> p;
    double* p_a[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        p_a[i] = a + i;
        p.push_back(p_a[i]);
    }

    cout << "Before sorting:" << endl;
    int size = p.size();
    for (int i = 0; i < size; ++i) {
        cout << *p[i] << " ";
    }
    cout << endl;

    SortPointers(p);

    cout << "After sorting:" << endl;
    for (int i = 0; i < size; ++i) {
        cout << *p[i] << " ";
    }
    cout << endl;

    cout << "The array of numbers:" << endl;
    for (int i = 0; i < SIZE; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
