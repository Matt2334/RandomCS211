#include <iostream>
using namespace std;
class Store{
    protected:  
        string name;
        string owner;
    public:
        Store(){
            name="Unknown";
            owner="Unknown";
        }
        Store(string n, string o){
            name=n;
            owner=o;
        }
        virtual void display()=0;
        void setName(string n){name=n;}
        void setOwner(string o){owner=o;}

        string getName(){return name;}
        string getOwner(){return owner;}
};
class Restaurant: public Store{
    protected:
        string cuisine;
    public:
        Restaurant():Store(){}
        Restaurant(string n, string o, string c):Store(n, o){
            cuisine=c;
        }
        Restaurant(const Restaurant &rhs){
            name = rhs.name;
            owner=rhs.owner;
            cuisine=rhs.cuisine;
        }
        Restaurant& operator=(const Restaurant &rhs){
            if(this==&rhs) return *this;
            name=rhs.name;
            owner=rhs.owner;
            cuisine=rhs.cuisine;
            return *this;
        }

        void display(){
            cout<<name<<" "<<owner<<" "<<cuisine<<endl;
        }
        void setCuisine(string c){cuisine=c;}
        string getCuisine(){return cuisine;}
        string operator+(const Restaurant &rhs){
            return name+" and "+rhs.name+"'s eatery";
        }
        
};
int main(){
    Restaurant one("Baked By Moe", "Moe", "Pastries");
    Restaurant two(one);
    cout<<one.getName()<<" "<<two.getName()<<endl;
    Restaurant three("abra", "Cadabra", "French");
    cout<<three.getCuisine()<<endl;
    cout<<three+one<<endl;
    return 0;
}