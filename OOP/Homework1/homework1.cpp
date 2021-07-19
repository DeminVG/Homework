#include <iostream>
#include <cmath>
#include <cstdint>
#include <cassert>

#define STACK_LENGTH 10

using namespace std;

class Power
{
    public:
    double a;
    double b;

    void set(){
        a = 2.1;
        b = 3.15;
    }

    void calculate(){
        cout << a << " to the extent of " << b << " = " << pow(a, b) << "\n";
    }
};

class RGBA
{
    private:
    uint8_t m_red = 0;
    uint8_t m_green = 0;
    uint8_t m_blue = 0;
    uint8_t m_alpha = 255;

    public:
    RGBA()
    {

    }

    RGBA(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    : m_red (red), m_green (green), m_blue (blue), m_alpha (alpha)
    {

    }

    void print(){
        cout << "m_red = " << +m_red << "\n";
        cout << "m_green = " << +m_green << "\n";
        cout << "m_blue = " << +m_blue << "\n";
        cout << "m_alpha = " << +m_alpha << "\n";
        
    }
};

class Stack
{
    private:
    int *m_arrey;
    int m_length;

    public:
    Stack (int length)  // Конструктор
    {
        assert (length > 0);
        m_arrey = new int[length];
        m_length = length;
    }

    ~Stack()    // Деструктор
    {
        delete[] m_arrey;
    }

    public:
    void reset()
    {
        for(int i = 0; i < STACK_LENGTH; i++){
            m_arrey[i] = 0;
        }
        m_length = 0;
    }

    public:
    bool push(int value)
    {
        if(m_length == STACK_LENGTH - 1){
            return false;
        }
        else{
            m_arrey[m_length] = value;
            m_length++;
            return true;
        }
    }

    public:
    bool pop()
    {
        if(m_length > 0){
            m_arrey[m_length] = 0;
            m_length--;
            return true;
        }
        else{
            return false;
        }
    }

    public:
    void print()
    {
        cout << "{";
        for(int i = 0; i < m_length; i++){
            cout << m_arrey[i] << " ";
        }
        cout << "}" << "\n";
    }
};

int main()
{
    // Lesson 1
    cout << "\nLesson 1 \n";
    Power power_A_B;
    power_A_B.set();
    power_A_B.calculate();

    // Lesson 2
    cout << "\nLesson 2 \n";
    RGBA rgba_one;
    rgba_one.print();
    RGBA rgba_two(5, 17, 34, 55);
    rgba_two.print();

    // Lesson 3
    cout << "\nLesson 3 \n";
    Stack stack(STACK_LENGTH);    //Выделяем стек на 10 элементов
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();
    
    return 0;
}