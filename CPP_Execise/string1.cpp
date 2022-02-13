// C++ Primer Plus 12.5
// Created by lhj on 2/13/22.
//

//string1.cpp -- String class methods

#include <cstring>
#include "string1.h"
using std::cin;
using std::cout;

//initializing static class member
int String::num_strings = 0;

//static methods
int String::HowMany()
{
    return num_strings;
}
//default ctor
String::String()
{
    len_ = 4;
    str_ = new char[1];
    str_[0] = '\0';
    num_strings++;
}
//ctor String from C string
String::String(const char *s)
{
    len_ = std::strlen(s);          //set size
    str_ = new char[len_ + 1];      //allot storage
    std::strcpy(str_, s);           //init pointer!!!!!!
    num_strings++;
}
//copy ctor
String::String(const String & str)
{
    num_strings++;                  //update object
    len_ = str.len_;                //same len
    str_ = new char[len_ + 1];      //allot space
    std::strcpy(str_, str.str_);    //copy str to new location
}
//dtor
String::~String()
{
    --num_strings;
    delete [] str_;
}

//    overloaded operator methods
/**
 * brief assign a string to a string
 * @param str
 * @return
 */
String &String::operator=(const String &str)
{
    if (this == &str)
        return *this;

    delete [] str_;

    len_ = str.len_;
    str_ = new char[len_ + 1];
    std::strcpy(str_, str.str_);
    return *this;
}
/**
 * assign a C-string to a string
 * @param cs
 * @return
 */
String &String::operator=(const char *cs)
{
    delete [] str_;

    len_ = std::strlen(cs);
    str_ = new char[len_ + 1];
    std::strcpy(str_, cs);
    return *this;
}
/**
 * read-write char access for non-const string
 * @param i
 * @return
 */
char &String::operator[](int i)
{
    return str_[i];
}
/**
 * read-only char access for const string
 * @param i
 * @return
 */
const char &String::operator[](int i) const
{
    return str_[i];
}

bool operator>(const String &st1, const String &st2)
{
    return st2 < st1;
}

bool operator<(const String &st1, const String &st2)
{
    return (std::strcmp(st1.str_, st2.str_) < 0);
}

bool operator==(const String &strlhs, const String &strrhs)
{
    return (std::strcmp(strlhs.str_, strrhs.str_) == 0);
}
//simple string output
ostream &operator<<(ostream &os, const String &str)
{
    os << str.str_;
    return os;
}
//quick and dirty string input
istream &operator>>(istream &is, String &str)
{
    char temp[String::CINLIM];
    is.get(temp, String::CINLIM);
    if (is)
        str = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}

//    overloaded operator friend


