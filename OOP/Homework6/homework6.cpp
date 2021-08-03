
#include <iostream>
#include <ostream>
#include <string>

using namespace std;


int input_int(const char* prompt_int)
{
    int a; 
    cout << prompt_int; 
    cin >> a;

    while (cin.fail() || cin.get() != '\n')
    {
        cin.clear();
        cin.ignore(9999, '\n');
        cin.sync();
        cerr << "Ошибка!\n\n" << prompt_int;
        cin >> a;
    }
    return a;
}

ostream& endll(ostream& stream){
    stream << "\n\n";
    stream.flush();
    return stream;
}

int main()
{
    setlocale(LC_ALL, "ru");

    // Lesson 1
    {
        cout << "Lesson 1:\n";
    
        cout << input_int("Введите число int: \n") << "\n\n";
    }

    // Lesson 2
    {
        cout << "Lesson 2:\n" << endll;
        cout << "Два перевода строки и сброс буфера.\n";
    }
    return 0;
}