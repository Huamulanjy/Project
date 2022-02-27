//  13.11 acctabc.h
// Created by lhj on 2/27/22.
//

#ifndef CPP_EXECISE_ACCTABC_H
#define CPP_EXECISE_ACCTABC_H

#include <iostream>
#include <string>


//Abstract base class
class AcctABC
{
private:
    std::string fullName;
    long acctNum;
    double balance;

protected:
    struct Formatting
    {
        std::ios_base::fmtflags flag;
        std::streamsize pr;
    };

    const std::string &FullName() const { return fullName; }
    long AcctNum() const { return acctNum; }
    Formatting SetFormat() const ;
    void Restore(Formatting & f) const ;

public:
    AcctABC(const std::string &s = "Nullbody", long an = -1, double bal = 0.0);

    void Deposit(double amt);

    virtual void  Withdraw(double amt) = 0;

    double Balance() const { return balance; };

    virtual void ViewAcct() const = 0;

    virtual ~AcctABC(){}
};

class Brass : public AcctABC
{
public:
    Brass(const std::string &s = "Nullbody", long an = -1, double bal = 0.0) : AcctABC(s, an, bal){};

    void  Withdraw(double amt) override;

    void ViewAcct() const override;

    virtual ~Brass() {};
};


class BrassPlus : public AcctABC
{
private:
    double maxLoan;
    double rate;
    double owesBank;

public:
    BrassPlus(const std::string &s = "Nullbody", long an = -1, double bal = 0.0,
              double ml = 500, double r = 0.1);

    BrassPlus(const Brass& ba, double ml = 500, double r = 0.1);

//    virtual void  Withdraw(double amt);
    void  Withdraw(double amt) override ;

//    virtual void ViewAcct() const ;
    void ViewAcct() const override ;

    void ResetMax(double m) { maxLoan = m; }

    void ResetRate(double r) { rate = r; }

    void ResetOwes() { owesBank = 0; }

};

#endif //CPP_EXECISE_ACCTABC_H


