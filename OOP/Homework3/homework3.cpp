#include <iostream>
#include <string>

using namespace std;

class Figure {
public:
    virtual double area() = 0;
};

class Parallelogram : public Figure {
private:
    double m_a;
    double m_h;

public:
    Parallelogram(double a = 1, double h = 1) {
        m_a = a;
        m_h = h;
    }
public:
    double area() override {
        return(m_a * m_h);
    }
};

class Circle : public Figure {
private:
    double m_r;

public:
    Circle(double r =1) { m_r = r; }

public:
    double area() override {
        return (3.1415926 * m_r * m_r);
    }
};

class Rectangle : public Parallelogram {
private:
    double m_a;
    double m_b;
public:
    Rectangle(double a = 1, double b = 1) {
        m_a = a;
        m_b = b;
    }
public:
    double area() override {
        return(m_a * m_b);
    }
};

class Square : public Parallelogram {
private:
    double m_a;
public:
    Square(double a = 1) {
        m_a = a;
    }
public:
    double area() override {
        return(m_a * m_a);
    }
};

class Rhombus : public Parallelogram {
private:
    double m_d1;
    double m_d2;
public:
    Rhombus(double d1 = 1, double d2 = 1) {
        m_d1 = d1;
        m_d2 = d2;
    }
public:
    double area() override {
        return(0.5 * m_d1 * m_d2);
    }
};

class Car {
private:
    string m_company;
    string m_model;
public:
    Car(string company = "", string model = "") {
        m_company = company;
        m_model = model;
        cout << "Конструктор класса Car: " << this << "\n";
    }
    virtual ~Car() {
        cout << "Деструктор класса Car: " << this << "\n";
    }
};

class PassengerCars : virtual public Car {
public:
    PassengerCars(string company, string name)
        : Car(company, name)
    {
        cout << "Конструктор класса PassengerCar: " << this << "\n";
    }
    virtual ~PassengerCars() {
        cout << "Деструктор класса PassengerCar: " << this << "\n";
    }
};

class Bus : virtual public Car {
public:
    Bus(string company, string name)
        : Car(company, name)
    {
        cout << "Конструктор класса Bus: " << this << "\n";
    }
    virtual ~Bus() {
        cout << "Деструктор класса Bus: " << this << "\n";
    }
};

class Minivan : public PassengerCars, public Bus{
public:
    Minivan(string company, string name)
        : PassengerCars(company, name), Bus(company, name)
    {
        cout << "Конструктор класса Minivan: " << this << "\n";
    }
    virtual ~Minivan() {
        cout << "Деструктор класса Minivan: " << this << "\n";
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    // Lesson 1
    cout << "Lesson 1:\n";

    Parallelogram parallelogram(4, 2);
    Figure* figure1 = &parallelogram;
    cout << "Площадь параллелограмма = " << figure1 -> area() << "\n";

    Circle circle(3);
    Figure* figure2 = &circle;
    cout << "Площадь круга = " << figure2 -> area() << "\n";

    Square square(3);
    Figure* figure3 = &square;
    cout << "Площадь квадрата = " << figure3 -> area() << "\n";

    Rectangle rectangle(3, 4);
    Figure* figure4 = &rectangle;
    cout << "Площадь прямоугольника = " << figure4 -> area() << "\n";

    Rhombus rhombus(4, 5);
    Figure* figure5 = &rhombus;
    cout << "Площадь ромба = " << figure5 -> area() << "\n";

    // Lesson 2
    cout << "\nLesson 2:\n";

    Car car1("Nissan", "Almera");
    PassengerCars passenger_car("Kia", "Rio");
    Bus bus("Toyota", "Hiace");
    Minivan("Hyndai","Starex");

    return 0;
}