#include <iostream>
namespace One{
class Restaurant{
    protected:
        std::string name;
        std::string location;
    public:
        Restaurant(){
            name="undetermined";
            location="undetermined";
        }
        Restaurant(std::string n, std::string l){
            name=n;
            location=l;
        }
        Restaurant(const Restaurant& origin){
            name=origin.name;
            location=origin.location;
        }
        Restaurant& operator=(const Restaurant& rhs){
            if(this==&rhs) return *this;
            name=rhs.name;
            location=rhs.location;
            return *this;
        }
        ~Restaurant(){}
        std::string getName(){return name;}
        std::string getLocation(){return location;}
};
class Bakery: public Restaurant{
    protected:
        int menu_items;
        std::string *menu;
    public:
        Bakery():Restaurant(){
            menu_items=0;
            menu= new std::string[menu_items];
        }

        Bakery(int num, std::string view[], std::string n, std::string l): Restaurant(n, l){
            menu_items=num;
            menu=new std::string[menu_items];
            for(int i=0; i<menu_items; i++) menu[i]=view[i];
        }
        Bakery(const Bakery& b): Restaurant(b.name, b.location){
            menu_items=b.menu_items;
            menu=new std::string[menu_items];
            for(int i=0;i<menu_items;i++) menu[i]=b.menu[i];
        }
        Bakery& operator=(const Bakery& rhs){
            if(this==&rhs) return *this;
            delete [] menu;
            menu_items=rhs.menu_items;
            menu=new std::string[menu_items];
            for(int i=0;i<menu_items;i++){
                menu[i]=rhs.menu[i];
            }
            return *this;
        }
        std::string getName(){return this->name;}
        std::string getLocation(){return this->location;}
        int getN(){return menu_items;}
        std::string getM(int i){return menu[i];}
        ~Bakery(){
            delete [] menu;
        }
};
}
int main() {
    // Creating a Restaurant object
    using namespace One;
    Restaurant A;
    std::cout << "Restaurant name: " << A.getName() << ", Location: " << A.getLocation() << std::endl;
    Restaurant C("CheeseHouse", "Central and 4th");
    std::cout << "Restaurant name: " << C.getName() << ", Location: " << C.getLocation() << std::endl;
    A.operator=(C);
    std::cout << "Restaurant A is now name: " << A.getName() << ", At Location: " << A.getLocation() <<"\n"<< std::endl;
    Restaurant G(C);
    std::cout << "Restaurant G name: " << G.getName() << ", Location: " << G.getLocation() << std::endl;
    // Creating a Bakery object
    std::string bakery_menu[] = { "Croissant", "Baguette", "Muffin" };
    Bakery B(3, bakery_menu, "Bakery X", "Downtown");
    std::cout << "Bakery name: " << B.getName() << ", Location: " << B.getLocation() << std::endl;
    std::cout << "Menu items:" << std::endl;
    for (int i = 0; i < B.getN(); i++) {
        std::cout << "- " << B.getM(i) << std::endl;
    }
    return 0;
}


