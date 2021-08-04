
#include <iostream>
#include <memory>

using namespace std;

class Date 
{
private:
    int m_day;
    int m_month;
    int m_year;
public:
    Date(int day = 1, int month = 1, int year = 2021)
    {
        m_day = day;
        m_month = month;
        m_year = year;
    }

    int getDay() const   { return m_day; }
    int getMonth() const { return m_month; }
    int getYear() const  { return m_year; }

    friend ostream& operator<< (ostream &out, const Date &date)
    {
        out << "Date: " << date.m_day << ". " << date.m_month << ". " << date.m_year << "\n";
        return out;
    }
};


int main()
{
    setlocale(LC_ALL, "ru");

    // Lesson 1
    {
        cout << "Lesson 1:\n";
        Date date (1, 2, 2020);
        //cout << date;
        unique_ptr<Date> today(new Date(8, 8, 2021));
        cout << *today;
        cout << "Day: " << today->getDay() << endl;
        cout << "Month: " << today->getMonth() << endl;
        cout << "Year: " << today->getYear() << endl;

        unique_ptr<Date> data;
        data = move(today);
        
        if(data == NULL) {
            cout << "Указатель data является нулевым." << endl;
        } else cout << *data;
        
        if(today == NULL) {
            cout << "Указатель today является нулевым." << endl;
        } else cout << *today;
        cout << endl;     
    }
    return 0;
}