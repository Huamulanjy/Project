//
// Created by lhj on 10/12/21.
//
#include "mytime0.h"
#include <iostream>


Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m) : hours(h), minutes(m){};

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;

    return sum;
}

void Time::Show() const
{
    std::cout << hours << " hours," << minutes << " minutes" ;
}

Time Time::operator+(const Time &t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;

    return sum;
}

Time Time::operator-(const Time &t) const
{
    Time diff;
    int total1, total2;
    total1 = t.minutes + 60 * t.hours;
    total2 = minutes + 60 * hours;
    diff.minutes = (total2 - total1) % 60;
    diff.hours = (total2 - total1) / 60;

    return diff;
}

Time Time::operator*(double multiply) const
{
    Time mult;
    long totalminutes = hours * multiply * 60 + minutes * multiply;
    mult.hours = totalminutes / 60;
    mult.minutes = totalminutes % 60;
    return mult;
}
