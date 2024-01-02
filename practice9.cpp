#include <iostream>
using namespace std;
class Money{
    public:
        int getDollars(){return dollars;}
        int getCents(){return cents;}
        double balance(){
            return ((dollars)+(cents/100.0));}
        void setDollars(int x){dollars=x;}
        void setCents(int y){cents=y;}
        void setBalance(int x, int y){
            dollars=x;
            cents=y;}

    private:
        int dollars, cents;
};
int main(){
    Money m, z;
    m.setDollars(15);
    cout<<m.getDollars()<<endl;
    m.setCents(13);
    cout<<m.getCents()<<endl;
    z.setBalance(27,50);
    cout<<"The balance of z is "<<z.balance()<<endl;
    return 0;
}
