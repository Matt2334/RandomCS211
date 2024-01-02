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
        Store(const Store& origin){
            store_name=origin.store_name;
            owner=origin.owner;
        }
        Store& operator=(const Store& rhs){
            if(this==&rhs) return *this;
            store_name=rhs.store_name;
            owner=rhs.owner;
            return *this;
        }
        ~Store(){}
        string getStoreName(){return store_name;}
        string getOwnerName(){return owner;}
        string operator+(const Store& rhs){
            return store_name+rhs.store_name;
        }
};
class Bank: public Store{
    protected:
        string location;
    public:
        Bank():Store(){
            location="undetermined";
        }
        Bank(string l, string storeName, string Owner):Store(storeName, Owner){
            location=l;
        }
        Bank(const Bank& origin):Store(origin.store_name, origin.owner){
            location=origin.location;
        }
        Bank& operator=(const Bank& rhs){
            if(this==&rhs) return *this;
            location=rhs.location;
            return *this;
        }
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
