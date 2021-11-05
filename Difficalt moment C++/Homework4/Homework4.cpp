#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T1, typename T2>
void insert_sort(T1& vec, const T2  num)
{
    const auto pos_insert(lower_bound(begin(vec), end(vec), num));
    vec.insert(pos_insert, num);
}

template<typename T>
void Print_vector(const T& vec)
{
    for (const auto i : vec) cout << i << ' ';
}

int main()
{
    // Lesson1
    cout << "Lesson1" << endl;
    vector<int> v1_int { 11, 7, 40, 25, 5 };
    vector<double> v2{12.73, 11.55, 17.36, 5.84, 9.11};

    sort(begin(v1_int), end(v1_int));
    insert_sort(v1_int, 9);
    Print_vector(v1_int);
    cout << endl;

    sort(begin(v2), end(v2));
    insert_sort(v2, 14.45);
    Print_vector(v2);
    cout << endl;

    return 0;
}