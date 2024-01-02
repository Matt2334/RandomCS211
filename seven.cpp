#include <iostream>
using namespace std;
class Store{
    protected:
        string store_name;
        string owner;
    public:
        Store(){
            store_name="Unknown";
            owner="Person";
        }
        Store(string s, string name){
            store_name=s;
            owner=name;
        }
        Store(const Store &orig){
            store_name= orig.store_name;
            owner=orig.owner;
        }
        Store& operator=(const Store &rhs){
            if(this==&rhs) return *this;
            store_name=rhs.store_name;
            owner=rhs.owner;
            return *this;
        }
        string getStoreName(){return store_name;}
        string getOwnerName(){return owner;} 
        void setStoreName(string sn){store_name=sn;}
        void setOwner(string name){owner=name;}
        Store operator+(const Store &rhs){
            Store temp(store_name+" and "+rhs.store_name, owner+" and "+rhs.owner);
            return temp;
        }
        ~Store(){}
};
class Bank: public Store{
    protected:
        string location;
    public:
        Bank():Store(){
            location="Uknown";
        }
        Bank(string l, string storeName, string owner):Store(storeName, owner){
            location=l;
        }
        Bank(const Bank &orig): Store(orig){
            location=orig.location;
        }
        string getLocation(){return location;}
        void setLocation(string l){location=l;}

        Bank& operator=(const Bank &rhs){
            if(this==&rhs) return *this;
            store_name=rhs.store_name;
            owner = rhs.owner;
            location=rhs.location;
            return *this;
        }
        string operator+(const Bank &rhs){cout<<"no clue"<<endl;}
        ~Bank(){}
};
int main(){
    Store a, b("Bobs Burgers", "Bob"), c(b);
    cout<<a.getStoreName()<<endl;
    cout<<b.getOwnerName()<<endl;
    cout<<c.getOwnerName()<<endl;
    c.operator=(a);
    cout<<c.getOwnerName()<<endl;
    return 0;
}