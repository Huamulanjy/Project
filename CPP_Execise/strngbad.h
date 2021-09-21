//
// Created by lhj on 9/21/21.
//
#include <iostream>
#ifndef STRNGBAD_H
#define STRNGBAD_H
class StringBad
{
private:
    int len;
    static int num_strings;  //静态成员是单独存储的，不是对象的一部分！！！故不能在声明中初始化！！！应在类方法文件中初始化。
                            //但是如果静态成员是const整数类型或者枚举型，反而可以在类声明中初始化。
    char * str;
public:
    explicit StringBad(const char * s);
    StringBad(const StringBad & st);
    StringBad();
    ~StringBad();
    StringBad &operator=(const StringBad & );
//    friend function
    friend std::ostream &operator<<(std::ostream & os, const StringBad & st);
};
#endif //STRNGBAD_H
