//  13.12acctABC.cpp
// Created by lhj on 2/27/22.
//

#include <iostream>
#include <string>
#include "acctabc.h"

using std::cout;
using std::endl;
using std::ios_base;
using std::string;

//Abstract Base Class
AcctABC::AcctABC(const std::string &s, long an, double bal)
{
    fullName = s;
    acctNum = an;
    balance = bal;
}

void AcctABC::Deposit(double amt)
{
    if (amt < 0)
        cout << "Negativce deposit not allowed; "
             << "deposit is cancelled.\n";
    else
        balance += amt;
}

void AcctABC::Withdraw(double amt)
{
    balance -= amt;
}

//protected methods
AcctABC::Formatting AcctABC::SetFormat() const {
    //set up ###.##format
    Formatting f;
    f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
    f.pr = cout.precision(2);
    return f;
}

void AcctABC::Restore(Formatting &f) const {
    cout.setf(f.flag, ios_base::floatfield);
    cout.precision(f.pr);
}

//Brass methods
void Brass::Withdraw(double amt) {
    //set up ###.##format
    Formatting f = SetFormat();

    if (amt < 0)
        cout << "withdraw amount must be positive; "
             << "withdrawal cancelled.\n";
    else if (amt <= Balance())
        AcctABC::Withdraw(amt);
    else
        cout << "withdraw amount of $" << amt << "excceeds your balance.\n"
             << "withdrawal cancelled.\n";

    Restore(f);
}

void Brass::ViewAcct() const
{
    //set up ###.##format
    Formatting f = SetFormat();

    cout << "Brass Client: " << FullName() << endl;
    cout << "AcctNum: " << AcctNum() << endl;
    cout << "Balance: " << Balance() << endl;
    //restore original format
    Restore(f);
}

//BrassPlus methods
BrassPlus::BrassPlus(const std::string &s, long an, double bal, double ml, double r) : AcctABC(s, an, bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r)
                    : AcctABC(ba)  //use implicit copy ctor
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void BrassPlus::ViewAcct() const
{
    //set up ###.##format
    Formatting f = SetFormat();

    cout << "BrassPlus Client: " << FullName() << endl;
    cout << "AcctNum: " << AcctNum() << endl;
    cout << "Balance: " << Balance() << endl;
    cout << "Maximum loan: $" << maxLoan << endl;
    cout << "Owed to bank: $" << owesBank << endl;
    cout.precision(3);            // ###.### format
    cout << "Loan Rate: " << 100 * rate << "%\n";

    Restore(f);
}

//redefine how Withdraw( )works
void BrassPlus::Withdraw(double amt)
{
    //set up ###.##format
    Formatting f = SetFormat();

    double bal = Balance();
    if (amt <= bal)
        AcctABC::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        cout << "Bank advance: $" << advance << endl;
        cout << "Finance charge: $" << advance * rate << endl;

        Deposit(advance);
        AcctABC::Withdraw(amt);
    } else
        cout << "Credit limit exceeded. Transaction cancelled.\n";

    Restore(f);
}