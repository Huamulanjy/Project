/*
// C++ Primer Plus 13.7
// Created by lhj on 2/13/22.
//

#ifndef CPP_EXECISE_BRASS_H
#define CPP_EXECISE_BRASS_H

#include <string>

//base class
class Brass
{
private:
    std::string fullName;
    long acctNum;
    double balance;

public:
    Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);

    void Deposit(double amt);

    virtual void  Withdraw(double amt);

    double Balance() const ;

    virtual void ViewAcct() const ;

    virtual ~Brass() {}

};

//child class
class BrassPlus : public Brass
{
private:
    double maxLoan;
    double rate;
    double owesBank;

public:
    BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0,
              double ml = 500, double r = 0.11125);

    BrassPlus(const Brass& ba, double ml = 500, double r = 0.11125);

//    virtual void  Withdraw(double amt);
    void  Withdraw(double amt) override ;

//    virtual void ViewAcct() const ;
    void ViewAcct() const override ;

    void ResetMax(double m) { maxLoan = m; }

    void ResetRate(double r) { rate = r; }

    void ResetOwes() { owesBank = 0; }

};
#endif //CPP_EXECISE_BRASS_H
*/
