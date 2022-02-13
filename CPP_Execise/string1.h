// C++ Primer Plus 12.4
// Created by lhj on 2/13/22.
//

#ifndef CPP_EXECISE_STRING1_H
#define CPP_EXECISE_STRING1_H

#include <iostream>
using std::ostream;
using std::istream;

class String
{
public:
//    constructor and other methods
    String();                   //degault ctor

    String(const char * s);     //ctor for c-string

    String(const String & str);     //copy ctor

    ~String();                  //dtor

    int length() const
    {
        return len_;
    }

//    overloaded operator methods
    String &operator=(const String & str);
    String &operator=(const char * cs);

    char &operator[](int i);
    const char &operator[](int i) const ;

//    overloaded operator friend
    friend bool operator>(const String & st1, const String & st2);
    friend bool operator<(const String & st1, const String & st2);
    friend bool operator==(const String & strlhs, const String & strrhs);

    friend ostream &operator<<(ostream & os, const String & str);
    friend istream &operator>>(istream & is, String & str);

//    static function
    static int HowMany();

private:
    char * str_;                    //pointer to string
    int len_;                       //length of string
    static int num_strings;         //number of objects
    static const int CINLIM = 80;   //cin input limit

};


#endif //CPP_EXECISE_STRING1_H
