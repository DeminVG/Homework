#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

template<typename T1, typename T2>
void insert_sort(T1& vec, const T2  num)
{
    const auto pos_insert(lower_bound(begin(vec), end(vec), num));
    vec.insert(pos_insert, num);
}

template<typename T>
void PrintVector(const T& vec)
{
    for (const auto a : vec) {
        cout << a << ' ';
    }
    cout << endl;
}

void FillDoubleVector(vector<double>& vec) {
    for (auto it = vec.begin(); it < vec.end(); ++it)
    {
        *it = (double)rand()*3/100;
    }
}

int main()
{
    // Lesson1
    cout << "Lesson1:" << endl;
    vector<int> v1_int { 11, 7, 40, 25, 5 };
    vector<double> v2{12.73, 11.55, 17.36, 5.84, 9.11};
    vector<char> v3{'d', 'r', 'w', 'v', 'k', 'z', 't', 'l', 'f', 'p'};

    sort(v1_int.begin(), v1_int.end());
    insert_sort(v1_int, 9);
    PrintVector(v1_int);
    
    sort(v2.begin(), v2.end());
    insert_sort(v2, 14.45);
    PrintVector(v2);

    sort(v3.begin(), v3.end());
    insert_sort(v3, 'a');
    PrintVector(v3);

    // Lesson2
    cout << endl << "Lesson2:" << endl;
    vector<double> v_double(10, 0);
    FillDoubleVector(v_double);
    PrintVector(v_double);
    vector<int> v_int(v_double.begin(), v_double.end());
    PrintVector(v_int);
    vector<double> res;
    transform(v_double.begin(), v_double.end(), v_int.begin(), back_inserter(res), minus<double>());
    PrintVector(res);
    transform(res.begin(), res.end(), res.begin(), [](double i) {return i * i; });
    PrintVector(res);
    double sum = accumulate(res.begin(), res.end(), 0.0);
    cout << "res = " << sum << endl;

    return 0;
}