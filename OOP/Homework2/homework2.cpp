#include <iostream>
#include <string>

using namespace std;

class Person
{
    public:
    string m_name;
    int m_age;
    char m_pol;
    uint m_weight;

    Person(string name, int age, char pol, uint weight)
    : m_name(name), m_age(age), m_pol(pol), m_weight(weight)
    {
        
    }

    public:
    void change_name(string name)
    {
        m_name = name;
    }

    public:
    void change_age(int age)
    {
        m_age = age;
    }

    public:
    void change_weight(uint weight)
    {
        m_weight = weight;
    }

};

class Student : public Person
{
    public:
    int m_year_of_study;
    static int number_of_students;

    public:
    Student (string name, int age, char pol, uint weight, int year_of_study)
    : Person (name, age, pol, weight), m_year_of_study(year_of_study)
    {
        number_of_students++;
    }

    public:
    void change_year_of_study(int year_of_study)
    {
        m_year_of_study = year_of_study;
    }

    public:
    void increase_year_of_study(int year)
    {
        m_year_of_study += year;
    }

    public:
    void show()
    {
        cout << "Name: " << m_name << "\n"; 
        cout << "Age: " << m_age << "\n";
        cout << "Pol: " << m_pol << "\n";
        cout << "Weight: " << m_weight << "\n" ;
        cout << "Year of study: " << m_year_of_study << "\n";
    }
};

int Student::number_of_students = 0;

class Fruit
{
    string m_name;
    string m_color;

    public:
    Fruit(string name, string color)
    :m_name(name), m_color(color)
    {

    }

    string getName() const
    {
        return m_name;
    }

    string getColor() const
    {
        return m_color;
    }
};

class Apple : public Fruit
{   
    public:
    Apple(string name = "apple", string color = "red")
    : Fruit(name, color){}
};

class Banana : public Fruit
{   
    public:
    Banana(string name = "banana", string color = "yellow")
    : Fruit(name, color){}
};

class GrannySmith : public Apple
{   
    public:
    GrannySmith(string name = "GrannySmith", string color = "green")
    : Apple(name, color){}
};

int main()
{   
    // Lesson 1
    cout << "Lesson 1\n";
    Student anton("Oleg", 23, 'm', 90, 3);
    anton.show();
    anton.change_name("Anton");
    anton.change_age(25);
    anton.change_weight(65);
    anton.change_year_of_study(2);
    anton.show();
    anton.increase_year_of_study(1);
    anton.show();
    Student oleg("Oleg", 26, 'm', 60, 1);
    Student anna("Anna", 21, 'f', 60, 2);
    
    cout << "Number_of_students: " << Student::number_of_students << "\n";

    // Lesson 2
    cout << "Lesson 2\n";
    Apple a("red");
    Banana b;
    GrannySmith c;
    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
    
    return 0;
}