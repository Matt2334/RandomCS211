// Prompt:

// Create a banking system simulation. Define a base class Account with protected member variables for accountNumber, balance, and accountType. 
// Implement public member functions getAccountInfo() to display basic account information.
// Allow functions withdraw and deposit to be overridden. Create a pure virtual function called display. 
// Derive two classes from Account: SavingsAccount and CheckingAccount. Use inheritance to allow derived classes access to the base class's protected members. 
// Override the withdraw() and deposit() functions in each derived class to handle specific account types. 
// Create instances of savings and checking accounts, perform withdrawals, deposits, and display account information for each account type. 
// Ensure that member variables are appropriately encapsulated using access specifiers, and demonstrate the inheritance, 
// use of protected members, and overridden functions in your implementation.

#include <iostream>
using namespace std;
class Account{
    protected:
        double balance;
        int accountNumber;
        string accountType;
    public:
        Account(){
            balance=0.0;
            accountNumber=0;
            accountType="Account";
        }
        Account(double b, int n, string type){
            balance=b;
            accountNumber=n;
            accountType=type;
        }
        virtual void withdraw(double d){
            cout<<"You withdrawed your entire balance of "<<balance<<"."<<endl;
            balance=0.0;
        }
        virtual void deposit(double b){
            balance+=b;
            cout<<"Your new balance is: " <<balance<<"."<<endl; 
        }
        virtual void display()=0;
        void getAccountInformation(){
            cout<<"Account type: "<<accountType<<" number: "<<accountNumber<<endl;
            cout<<"Your current balance is: "<<balance<<"."<<endl;
        }
    
};
class SavingsAccount: public Account{
    public:
        SavingsAccount():Account(){
        }
        SavingsAccount(double bal, int n, string t):Account(bal, n, t){}
        void withdraw(double b){
            balance-=b;
            cout<<"Your have withdrawn "<<b<<" from your balance"<<endl;
            cout<<"Your current balance is "<<balance<<endl;
        }
        void deposit(double b){
            balance+=b;
            cout<<"Your have deposited "<<b<<" into your balance"<<endl;
            cout<<"Your current balance is "<<balance<<endl;
        }
        void display(){
            cout<<"Account type: "<<accountType<<"\nnumber: "<<accountNumber<<endl;
            cout<<"Your current balance is: "<<balance<<"."<<endl;
        }
};
class CheckingAccount: public Account{
    public:
        CheckingAccount():Account(){}
        CheckingAccount(double bal,int n, string t):Account(bal, n, t){}
        void withdraw(double b){
            balance-=b;
            cout<<"Your blue to withdraw this:"<<b<<" amount from your balance"<<endl;
            cout<<"Whatever, your updated balance is "<<balance<<endl;
        }
        void deposit(double b){
            balance+=b;
            cout<<"Rolling in green I see. You have deposited "<<b<<" into your balance"<<endl;
            cout<<"The new balance is "<<balance<<endl;
        }
        void display(){
            cout<<"Account type: "<<accountType<<"\nnumber: "<<accountNumber<<endl;
            cout<<"Your current balance is: "<<balance<<"."<<endl;
        }
};

int main(){
    SavingsAccount sA;
    sA.deposit(153.2);
    sA.display();

    SavingsAccount sB(10.1, 123, "Savings Account");
    sB.deposit(2304.1);
    sB.display();


}
