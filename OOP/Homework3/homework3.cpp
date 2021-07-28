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

class Fraction {
private:
    int m_numerator = 1;
    int m_denominator = 1;
public:
    Fraction(int numerator = 1, int denominator = 1) {
        m_numerator = numerator;
        if (!denominator) {
            cout << "Знаменеатель не может быть равен 0!\n";
        }
        else {
            m_denominator = denominator;
        }
    }

    int Get_numerator(const Fraction& other) {
        return other.m_numerator;
    }

    int Get_denominator(const Fraction& other) {
        return other.m_denominator;
    }

    void Print() {
        cout << this->m_numerator << "/" << this->m_denominator;
    }

    Fraction operator+ (const Fraction& other) {
        Fraction temp;
        temp.m_numerator = this->m_numerator * other.m_denominator + other.m_numerator * this->m_denominator;
        temp.m_denominator = this->m_denominator * other.m_denominator;
        return temp;
    }

    Fraction operator- (const Fraction& other) {
        Fraction temp;
        temp.m_numerator = this->m_numerator * other.m_denominator - other.m_numerator * this->m_denominator;
        temp.m_denominator = this->m_denominator * other.m_denominator;
        return temp;
    }

    Fraction operator* (const Fraction& other) {
        Fraction temp;
        temp.m_numerator = this->m_numerator * other.m_denominator;
        temp.m_denominator = this->m_denominator * other.m_numerator;
        return temp;
    }

    Fraction operator/ (const Fraction& other) {
        Fraction temp;
        temp.m_numerator = this->m_numerator * other.m_numerator;
        temp.m_denominator = this->m_denominator * other.m_denominator;
        return temp;
    }

    Fraction operator- () {
        Fraction temp;
        temp.m_numerator = -this->m_numerator;
        temp.m_denominator = this->m_denominator;
        return temp;
    }

    bool operator== (const Fraction& other) {
        return this->m_numerator == other.m_numerator && this->m_denominator == other.m_denominator;
    }

    bool operator!= (const Fraction& other) {
        return !(this->m_numerator == other.m_numerator && this->m_denominator == other.m_denominator);
    }
    bool operator< (const Fraction& other) {
        return (this->m_numerator * other.m_denominator < other.m_numerator * this->m_denominator);
    }

    bool operator> (const Fraction& other) {
        return (this->m_numerator * other.m_denominator > other.m_numerator* this->m_denominator);
    }

    bool operator>= (const Fraction& other) {
        return !(this->m_numerator * other.m_denominator < other.m_numerator* this->m_denominator);
    }

    bool operator<= (const Fraction& other) {
        return !(this->m_numerator * other.m_denominator > other.m_numerator * this->m_denominator);
    }
};

int main() {
    setlocale(LC_ALL, "ru");

    // Lesson 1
    {
        cout << "Lesson 1:\n";

        Parallelogram parallelogram(4, 2);
        Figure* figure1 = &parallelogram;
        cout << "Площадь параллелограмма = " << figure1->area() << "\n";

        Circle circle(3);
        Figure* figure2 = &circle;
        cout << "Площадь круга = " << figure2->area() << "\n";

        Square square(3);
        Figure* figure3 = &square;
        cout << "Площадь квадрата = " << figure3->area() << "\n";

        Rectangle rectangle(3, 4);
        Figure* figure4 = &rectangle;
        cout << "Площадь прямоугольника = " << figure4->area() << "\n";

        Rhombus rhombus(4, 5);
        Figure* figure5 = &rhombus;
        cout << "Площадь ромба = " << figure5->area() << "\n";
    }

    // Lesson 2
    {
        cout << "\nLesson 2:\n";

        Car car1("Nissan", "Almera");
        PassengerCars passenger_car("Kia", "Rio");
        Bus bus("Toyota", "Hiace");
        Minivan("Hyndai", "Starex");
    }

    // Lesson 3
    {
        cout << "\nLesson 3:\n";

        Fraction f1(1, 2);
        Fraction f2(1, 2);
        Fraction f3(2, 3);

        bool result1 = f1 == f2;
        f1.Print();
        cout << " == ";
        f2.Print();
        cout << " результат: " << result1 << "\n";

        bool result2 = f1 != f2;
        f1.Print();
        cout << " != ";
        f2.Print();
        cout << " результат: " << result2 << "\n";

        bool result3 = f2 != f3;
        f2.Print();
        cout << " != ";
        f3.Print();
        cout << " результат: " << result3 << "\n";

        bool result4 = f2 == f3;
        f2.Print();
        cout << " == ";
        f3.Print();
        cout << " результат: " << result4 << "\n";

        bool result5 = f2 < f3;
        f2.Print();
        cout << " < ";
        f3.Print();
        cout << " результат: " << result5 << "\n";

        bool result6 = f2 > f3;
        f2.Print();
        cout << " > ";
        f3.Print();
        cout << " результат: " << result6 << "\n";

        bool result7 = f2 >= f1;
        f2.Print();
        cout << " >= ";
        f1.Print();
        cout << " результат: " << result7 << "\n";

        bool result8 = f2 <= f1;
        f2.Print();
        cout << " <= ";
        f1.Print();
        cout << " результат: " << result8 << "\n";

        Fraction f4 = f3 + f2;
        f3.Print();
        cout << " + ";
        f2.Print();
        cout << " = ";
        f4.Print();

        Fraction f5 = f3 - f2;
        cout << endl;
        f3.Print();
        cout << " - ";
        f2.Print();
        cout << " = ";
        f5.Print();

        Fraction f6 = f3 * f2;
        cout << endl;
        f3.Print();
        cout << " * ";
        f2.Print();
        cout << " = ";
        f6.Print();

        Fraction f7 = f3 / f2;
        cout << endl;
        f3.Print();
        cout << " / ";
        f2.Print();
        cout << " = ";
        f7.Print();
        cout << endl;

        Fraction f8 = -f3;
        f8.Print();
        cout << endl;
    }

    return 0;
}