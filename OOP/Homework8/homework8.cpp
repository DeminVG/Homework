#include <iostream>

using namespace std;

template<class T1, class T2>
double div(T1 a, T2 b)
{
    if(b == 0)
    {
        throw b;
    }
    else
    {
        return a/b;
    }
}

void DivizionByZerro()
{
    cout << "Деление на 0!!!" << endl;
}

int main() {
    setlocale(LC_ALL, "ru");

    // Lesson 1
    {
        cout << "\nLesson 1\n";
        
        try
        {
            cout << div(5.0, 0) << endl;
        }
        catch(const int ex)
        {
            DivizionByZerro();
            cerr << "Делитель = " << ex << endl;

        }
    }
    return 0;
}