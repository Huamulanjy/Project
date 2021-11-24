//
// Created by lhj on 10/12/21.
//

#ifndef CPP_EXECISE_MYTIME0_H
#define CPP_EXECISE_MYTIME0_H

#include <ostream>
using std::ostream;


class Time
{
public:
    Time();
    Time(int h, int m = 0);
//    ~Time();

    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    void Show() const ;

    Time Sum(const Time & t) const ;

    Time operator+(const Time & t) const ;

    Time operator-(const Time & t) const ;

    Time operator*(double multiply) const ;
//类的友元函数是[非成员函数]，但是访问权限与成员函数相同
    friend Time operator*(double m, const Time & t);
// bad << ,因为不能连续使用<<输出
/*    friend void operator<<(ostream & os, const Time & t);*/

//    normal;Time(<<) ostream(<<)连用
    friend std::ostream & operator<<(std::ostream & os, const Time & t);
private:
    int hours;
    int minutes;
};
#endif //CPP_EXECISE_MYTIME0_H
