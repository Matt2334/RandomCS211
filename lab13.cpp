#include <iostream>
using namespace std;
class BankAccount
{
    private:
        int accountDollars;
        int accountCents;
        double rate;

    public:
        // extracts the dollars and cents from the balance
        BankAccount(double balance, double rate)
        {
            string s=to_string(balance), a="", b="";
            bool f=true;
            for(int i=0; i<s.length(); i++){
                if(s[i]=='.') f=false;
                if(f) a+=s[i];
                if(s[i]!='.' && !f && s[i]!='0') b+=s[i];
            }
            accountDollars=stoi(a);
            accountCents=stoi(b);
            this->rate = rate;
        }

        // takes in dollars and cents as ints
        BankAccount(int dollars, int cents, double rate)
        {
            accountDollars = dollars;
            accountCents = cents;
            this->rate = rate;
        }
        // whole dollar amounts
        BankAccount(int dollars, double rate)
        {
            accountDollars = dollars;
            accountCents=0;
            this->rate = rate;
        }
        BankAccount()
        {
            accountDollars = 0;
            accountCents = 0;
            rate = 0.0;
        }
        int getDollars() { return accountDollars; }
        int getCents() { return accountCents; }
        double getRate(){return rate;}
};
int main()
{
    // double dollars and double rate
    BankAccount first = BankAccount(13.57, 2.0);
    cout<<first.getDollars()<<endl;
    cout<<first.getCents()<<endl;
    cout<<first.getRate()<<endl;
    cout<<endl;

    // no parameters, default
    BankAccount second= BankAccount();
    cout<<second.getDollars()<<endl;
    cout<<second.getCents()<<endl;
    cout<<second.getRate()<<endl;
    cout<<endl;

    // int dollars, int cents, and double rate
    BankAccount third= BankAccount(12, 97, 3.5);
    cout<<third.getDollars()<<endl;
    cout<<third.getCents()<<endl;
    cout<<third.getRate()<<endl;
    cout<<endl;
    
    // int dollars and double rate
    BankAccount fourth= BankAccount(15, 7.0);
    cout<<fourth.getDollars()<<endl;
    cout<<fourth.getCents()<<endl;
    cout<<fourth.getRate()<<endl;
    cout<<endl;
}
