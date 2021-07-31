#include <iostream>
#include <string>

using namespace std;

// class == typename
// class -> C++
// шаблоны функций
/*
template<class T1, class T2>  
void Sum(T1 a, T2 b){
    cout << a << endl;
    cout << b << endl;
}

template<class T>
T Power(T a){
    return a*a;
}

class Point 
{
private:
    double x;
    double y;
    double z;
public:
    Point() {
        x = y = z = 0;
    }
    
    Point (double x, double y, double z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }

};



// шаблоны классов

template<typename T1, typename T2>
class MyClass
{
private:
    T1 value1;
    T2 value2;
public:
    MyClass(T1 value1, T2 value2) {
        this->value1 = value1;
        this->value2 = value2;
    }

    void DataTypeSize() {
        cout << sizeof(value1) << endl;
        cout << sizeof(value2) << endl;
    }
};
*/

template<class T>
class Pair1
{
private:
    T a;
    T b;
public:
    Pair1(T a, T b) {
        this->a = a;
        this->b = b;
    }

    T first() {
        return this->a;
    }

    T second() {
        return this->b;
    }
};

template<class T1, class T2>
class Pair2
{
private:
    T1 a;
    T2 b;
public:
    Pair2(T1 a, T2 b) {
        this->a = a;
        this->b = b;
    }

    T1 first() {
        return this->a;
    }

    T2 second() {
        return this->b;
    }
};

template<class T> 
class Pair
{
private:
    string a;
    T b;
public:
    Pair(string a, T b) {
        this->a = a;
        this->b = b;
    }

    string first() {
        return this->a;
    }

    T second() {
        return this->b;
    }
};
/*
template<class T>
class StringValuePair : public Pair<int, T>(a, b) {
        //this->a = a;
        //this->b = b;
    
    
};
*/
template<class T>
class StringValuePair : public Pair<T> {
public:
    StringValuePair(string a, T b) : Pair<T>(a, b) {

    }

};

int main() {
    setlocale(LC_ALL, "ru");

    // Lesson 1
    {
        cout << "\nLesson 1\n";
        
        Pair1<int> p1(6, 9);
        cout <<"Pair: " << p1.first() << " " << p1.second() << endl;
        
        Pair1<double> p2(3.4, 7.8);
    cout <<"Pair: " << p2.first() << " " << p2.second() << endl;
    }

    // Lesson 2
    {
        cout << "\nLesson 2\n";
        
        Pair2<int, double> p1(6, 7.8);
        cout <<"Pair: " << p1.first() << " " << p1.second() << endl;
        
        Pair2<double, int> p2(3.4, 5);
        cout <<"Pair: " << p2.first() << " " << p2.second() << endl;
    }

    // Lesson3
    {
        cout << "\nLesson 3\n";

        StringValuePair<int> svp("Amazing", 7);
        cout <<"Pair: " << svp.first() << " " << svp.second() << endl;
    }

    return 0;
}