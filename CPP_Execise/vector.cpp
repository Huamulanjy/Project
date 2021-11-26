//
// Created by lhj on 11/25/21.
//
#include <cmath>
#include "vector.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
    //compute degrees in one radian
    const double Rad_to_deg = 45.0 / atan(1.0); //57.29577du (pi=3.14 ~ 180du)

    //private methods
    void Vector::set_mag()
    {
        mag = sqrt(x * x + y * y);
    }

    void Vector::set_ang()
    {
        ang = atan2(y, x);
    }
    //set x from polar coorddinate
    void Vector::set_x()
    {
        x = mag * cos(ang);
    }
    //set y from polar coorddinate
    void Vector::set_y()
    {
        y = mag * sin(ang);
    }

    //default constructor
    Vector::Vector()
    {
        x = y = mag = ang = 0.0;
        mode = RECT;
    }
    //constructor Vector from rectangular if form is r
    //(the default) or else from polar if form is p
    Vector::Vector(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else
            {
            cout << "Incorrect 3rd arguement to Vector() -- ";
            cout << "Vector set to 0 \n";
                x = y = mag = ang = 0.0;
                mode = RECT;
        }
    }
    //reset Vector from rectangular if form is r
    //(the default) or else from polar if form is p
    void Vector::reset(double n1, double n2, Mode form)
    {
        mode = form;
        if (form == RECT)
        {
            x = n1;
            y = n2;
            set_mag();
            set_ang();
        } else if (form == POL)
        {
            mag = n1;
            ang = n2 / Rad_to_deg;
            set_x();
            set_y();
        } else
        {
            cout << "Incorrect 3rd arguement to Vector() -- ";
            cout << "Vector set to 0 \n";
            x = y = mag = ang = 0.0;
            mode = RECT;
        }
    }
    //destructor
    Vector::~Vector()= default;

    void Vector::rect_mode()
    {
        mode = RECT;
    }

    void Vector::polar_mode()
    {
        mode = POL;
    }

    //operator overloading +
    Vector Vector::operator+(const Vector &b) const
    {
        return Vector(x + b.x, y + b.y);
    }
    //-
    Vector Vector::operator-(const Vector &b) const
    {
        return Vector(x - b.x, y - b.y);
    }
    //reverse sign of vector
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }
    //multiply vector by n
    Vector Vector::operator*(double n) const
    {
        return Vector(n * x, n * y);
    }

    //friend func methods
    //multiply vector by n
    Vector operator*(double n, const Vector & a)
    {
        return a * n;
    }
    //display rect coordinates if mode is RECT
    //display polar coordinates if mode is POL
    std::ostream &operator<<(std::ostream & os, const Vector & v)
    {
        if (v.mode == Vector::RECT)
        {
            os << "(x,y) = (" << v.x << ", " << v.y << ")";
        }else if (v.mode == Vector::POL)
        {
            os << "(m,a) = (" << v.mag << ", " << v.ang * Rad_to_deg << ")";
        } else
        {
            os << "Vector object mode is invalid!!!";
        }
        return os;
    }

}