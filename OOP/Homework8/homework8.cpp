#include <iostream>

using namespace std;

template<class T1, class T2>
double div(T1 a, T2 b)
{
    if (b == 0)
    {
        throw b;
    }
    else
    {
        return a / b;
    }
}

void DivizionByZerro()
{
    cout << "Деление на 0!!!" << endl;
}

class Ex
{
private:
    double m_x;
public:
    Ex(double x)
    {
        m_x = x;
    }
    ~Ex()
    {}
};

class Bar
{
private:
    double m_y;
public:
    Bar()
    {
        m_y = 0;
    }

    ~Bar()
    {}

    void set(double a)
    {
        if ((m_y + a) > 100)
        {
            Ex(a * m_y);
            throw exception("y + a > 100");
        }
        else
        {
            m_y = a;
        }
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    // Lesson 1
    {
        cout << "\nLesson 1\n";

        try
        {
            cout << div(5.0, 0) << endl;
        }
        catch (const int ex)
        {
            DivizionByZerro();
            cerr << "Делитель = " << ex << endl;

        }
    }

    // Lesson2
    {
        cout << "\nLesson 2\n";

        Bar bar;
        int value = 1;

        try
        {
            while (value != 0)
            {
                cout << "Введите целое число: ";
                cin >> value;
                bar.set(value);
            }
        }
        catch (const exception& ex)
        {
            cerr << ex.what();
            //Ex(ex);
        }

    }

    return 0;
}