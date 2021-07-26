#include <iostream>
#include <cmath>

class Figure    // абстрактный класс
{
public:
    virtual double area() =0;
};

class Parallelogram : public Figure {
/*
private:
    double m_a = 1;
    double m_h = 1;
    
public:
    Parallelogram(double a, double h){
        m_a = a;
        m_h = h;
    }
public:
    double area() {
        return(m_a * m_h);
    }
    */
};

class Circle : public Figure {
private:
    double m_r = 1;
    
public:
    Circle(double r){ m_r = r; }
    
public:
    double area() {
        return (3.1415926 * m_r * m_r);
    }
};

class Rectangle : public Parallelogram {
private:
    double m_a = 1;
    double m_b = 1;
public:
    Rectangle (double a, double b){
        m_a = a;
        m_b = b;
    }
public:
    double area() {
        return(m_a * m_b);
    }
};

class Square : public Parallelogram {
private:
    double m_a = 1;
public:
Square(double a){
    m_a = a;
}
public:
    double area() {
        return(m_a * m_a);
    }
};

class Rhombus : public Parallelogram {
private:
    double m_d1 = 1;
    double m_d2 = 1;
public:
    Rhombus(double d1, double d2){
        m_d1 = d1;
        m_d2 = d2;
    }
public:
    double area() {
        return(0.5 * m_d1 * m_d2);
    }
};

int main() {
/*
    Parallelogram parallelogram1(4, 2);
    std::cout << parallelogram1.area() << "\n";
*/
    Circle circle1(3);
    std::cout << circle1.area() << "\n";
    
    Square square1(3);
    std::cout << square1.area() << "\n";
  
    Rectangle rectangle1(3, 4);
    std::cout << rectangle1.area() << "\n";
    
    Rhombus rhombus1(4, 5);
    std::cout << rhombus1.area() << "\n";
    return 0;
}