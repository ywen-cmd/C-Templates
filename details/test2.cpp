#include<iostream>
using namespace std;

class Account{
public:
    static double rate(){return interestRate;}
    // static void rate();

    static double interestRate;
    static constexpr int period =30;
    double daly_tb1[period];
};

double Account::interestRate = 10;
constexpr int Account::period  ;

int main(){
    Account a;
    const int& b = Account::period;
    cout<<"hi"<<ends;
    cout<<"em"<<endl;
    return 0;
}