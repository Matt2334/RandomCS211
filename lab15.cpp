#include <iostream>
using namespace std;
class Money{
    private:
        int dollars, cents;
    public:
        Money(){
            dollars=27;
            cents=50;
        }
        int getDollars(){return dollars;}
        int getCents(){return cents;}
        double balance(){
            return ((dollars)+(cents/100.0));}
        void setDollars(int x){dollars=x;}
        void setCents(int y){cents=y;}
        void setBalance(int x, int y){
            dollars=x;
            cents=y;}
// <, <=, >, and >=
        bool operator< (const Money& money2) const{
            if(dollars==money2.dollars){
                return (cents<money2.cents);
            }
            return (dollars<money2.dollars);
        }
        bool operator<= (const Money& money2) const{
            if(dollars==money2.dollars){
                return (cents<=money2.cents);
            }
            return (dollars<money2.dollars);
        }
        bool operator> (const Money& money2) const{
            if(dollars==money2.dollars){
                return (cents>money2.cents);
            }
            return (dollars>money2.dollars);
        }
        bool operator>= (const Money& money2) const{
            if(dollars==money2.dollars){
                return (cents>=money2.cents);
            }
            return (dollars>money2.dollars);
        }
};
int main(){
    Money m, z;
    m.setDollars(15);
    m.setCents(35);
    cout<<"The balance of m is: "<<m.balance()<<endl;
   
    cout<<"The balance of z is: "<<z.balance()<<endl;
    
    //Using overloaded operators
    cout<<"M<Z "<<(m<z)<<endl;
    cout<<"M>Z "<<(m>z)<<endl;
    cout<<"M<=Z "<<(m<=z)<<endl;
    cout<<"M>=Z "<<(m>=z)<<endl;
    return 0;
}
