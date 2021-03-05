#include<iostream>
#include<iomanip>
using namespace std;


class Date
{
//输入
friend istream& operator>>(istream& _cin, Date& d);
friend ostream& operator<<(ostream& _cout, Date& d);
public:
    //获得每月天数
    int GetDays(int year, int month)
    {
        static int daysArr[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
        int days = daysArr[month];
        if((days == 28) 
           && ((year % 4 == 0 && year % 100 != 0) 
           || (year % 400 == 0)))
        {
            days = 29;
        }
        
        return days;
    }
    
    //日期构造函数
    Date(int year=1990, int month=1, int day=1)
    {
        _year = year;
        _month = month;
        _day = day;
    }
    
    //日期＋天数
    Date& operator+=(int days)
    {
        _day += days;
        //日期进位
        while(_year > 0
             && _month < 13
             && _day > GetDays(_year, _month))
        {
            _day -= GetDays(_year, _month);
            ++_month;
            if(_month > 12)
            {
                ++_year;
                _month = 1;
            }
        }
        
        return *this;
    }
    
private:
    int _year;
    int _month;
    int _day;
};


//输入
istream& operator>>(istream& _cin, Date& d)
{
    _cin>>d._year;
    _cin>>d._month;
    _cin>>d._day;
    
    return _cin;
}
//输出
ostream& operator<<(ostream& _cout, Date& d)
{
    _cout<<d._year<<"-"<<setfill('0')<<setw(2)<<d._month<<"-"<<setfill('0')<<setw(2)<<d._day;
    
    return _cout;
}


int main()
{
    int m = 0;
    int days = 0;
    cin>>m;
    Date d[m];
    while(m > 0)
    {
        
        cin>>d[m];
        scanf("%d\n", &days);
        d[m] +=days;
        cout<<d[m]<<endl;;
        --m;
    }
    
    return 0;
}