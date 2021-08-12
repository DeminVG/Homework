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

    friend void ptrIsNull (Date *date, string str)
    {
        if(date == NULL )
        {
            cout << "Указатель " << str << " является нулевым!" << endl;
        } else cout << *date;
    }

    friend Date* lateDate(Date *date1, Date *date2)
    {
        Date* res;
       
        date1->m_year * 365 + date1->m_month * 30 + date1->m_day > date2->m_year * 365 + date2->m_month * 30 + date2->m_day ? res = date1 : res = date2;
        return res;
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
        
        ptrIsNull(data.get(), "data");
        ptrIsNull(today.get(), "today");
       
        cout << endl;     
    }

    // Lesson 2
    {
        cout << "Lesson 2:" << endl;

        unique_ptr<Date> data1(new Date(17, 8, 2022));
        unique_ptr<Date> data2(new Date(8, 8, 2021));
        cout << *lateDate(data1.get(), data2.get()) << "является более поздней датой." << endl;
    }
    

    return 0;
}