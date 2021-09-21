//
// Created by lhj on 9/21/21.
//

#include <cstring>
#include "strngbad.h"

using std::cout;

int StringBad::num_strings = 0;

StringBad::StringBad(const char * s)
{
    len = std::strlen(s);
    str = new char[len + 1];
    std::strcpy(str, s);
    num_strings++;
    cout << num_strings << ": \"" << str
            << "\"object created. call overload constructor func\n";   //for your information
}      //overload constructor func

StringBad::StringBad(const StringBad & st)     //copy constructor func
{
    num_strings++;
    len = st.len;
    str = new char[len + 1];
    std::strcpy(str, st.str);
    cout << num_strings << ": \"" << str
         << "\"object created.  call copy constructor func\n";   //for your information
}

StringBad::StringBad()
{
    len = 4;
    str = new char[4];
    std::strcpy(str, "c++");
    num_strings++;
    cout << num_strings << ": \"" << str
         << "\"default object created\n";
}     //default constructor func

StringBad::~StringBad()
{
    cout << "\"" << str << "\"object deleted, ";
    --num_strings;
    cout << num_strings << "left\n";
    delete [] str;
}     //destructor func

std::ostream & operator<<(std::ostream & os, const StringBad & st)
{
    os << st.str;
    return os;
}   //overload <<

StringBad & StringBad::operator=(const StringBad & st)
{
    if (this == &st)        //object assigned to itself
        return *this;       //all done;return
    delete [] str;  //free old string   释放掉旧的字符串"c++"
    len = st.len;
    str = new char[len + 1];    //get space for new string
    std::strcpy(str, st.str);   //copy the string
    return *this;           //return reference to invoking object 返回对调用对象的引用，以便连续赋值操作s0 = s1 = s2;
}           //overload =
