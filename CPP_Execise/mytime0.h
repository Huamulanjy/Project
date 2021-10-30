//
// Created by lhj on 10/12/21.
//

#ifndef CPP_EXECISE_MYTIME0_H
#define CPP_EXECISE_MYTIME0_H

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

private:
    int hours;
    int minutes;
};
#endif //CPP_EXECISE_MYTIME0_H
