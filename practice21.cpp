#include <iostream>
using namespace std;
class Account {
    protected:
        double balance;
    public:
        Account(){
            balance=0.0;
        }
        Account(double b){
            balance=b;
        }
        double getBalance(){return balance;}
        void setBalance(double b){balance=b;}
        virtual string type() const { return "Account"; }
};
class CheckingAccount: public Account {
    public:
        CheckingAccount(): Account(){}
        CheckingAccount(double b):Account(b){}
        double getBalance(){return balance;}
        void setBalance(double b){balance=b;}
        string type() const { return "CheckingAccount"; }
};
class SavingsAccount: public Account {
    public:
        SavingsAccount(): Account(){}
        SavingsAccount(double b):Account(b){}
        double getBalance(){return balance;}
        void setBalance(double b){balance=b;}
        string type() const { return "SavingsAccount";}
};
void print_account_type(const Account &acct) {
	cout << acct.type() << endl;
}
int main() {
	Account acct(1000.0);
	CheckingAccount checking(1000.0);
	SavingsAccount saving;
	print_account_type(acct);
	print_account_type(checking);
	print_account_type(saving);
    
    cout<<saving.getBalance()<<endl;
    saving.setBalance(200.5);
    cout<<saving.getBalance()<<endl;
	return 0;
}
