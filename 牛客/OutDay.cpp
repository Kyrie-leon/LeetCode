#include<iostream>
using namespace std;


class Date
{
friend istream& operator>>(istream& _cin, Date& d);
public:
    int GetMonthDays(int year, int month)
    {
        
        static int daysArr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int days = daysArr[month];
        
        if(month == 2 
           && (_year % 4 == 0 && _year % 100 != 0)
           || (year % 400 == 0))
        {
            days = 29;
        }
        
        return days;
    }
    
    Date(int year=2012, int month = 12, int day = 31)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    
    int GetDays()
    {
        if(_year <=0
          || _month <=0 || _month >12
          || _day > GetMonthDays(_year, _month)
          || _day <= 0)
        {
            return -1;
        }
        
        int days = _day;
        --_month;
        while(_month > 0)
        {
            days += GetMonthDays(_year, _month--);
        }
        return days;
    }
    
private:
    int _year;
    int _month;
    int _day;
};


istream& operator>>(istream& _cin, Date& d)
{
    _cin>>d._year;
    _cin>>d._month;
    _cin>>d._day;
    
    return _cin;
}


int main()
{
    Date d;
    while(cin>>d)
    {
        int days = d.GetDays();
        cout<<days<<endl;
    }
    return 0;
}