// She will give us class, data members, and a constructor. 
// We will be asked to write the destructor, copy constructor, 
// and assignment operation, and we will also need to overload one operation (for example plus). 
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

}
int main(){
    Store a, b("Bobs Burgers", "Bob"), c(b);
    cout<<a.getStoreName()<<endl;
    cout<<b.getOwnerName()<<endl;
    cout<<c.getOwnerName()<<endl;
    c.operator=(a);
    cout<<c.getOwnerName()<<endl;
    return 0;
}









// #include <iostream>
// namespace One{
// class Restaurant{
//     protected:
//         std::string name;
//         std::string location;
//     public:
//         Restaurant(){
//             name="undetermined";
//             location="undetermined";
//         }
//         Restaurant(std::string n, std::string l){
//             name=n;
//             location=l;
//         }
//         Restaurant(const Restaurant& origin){
//             name=origin.name;
//             location=origin.location;
//         }
//         Restaurant& operator=(const Restaurant& rhs){
//             if(this==&rhs) return *this;
//             name=rhs.name;
//             location=rhs.location;
//             return *this;
//         }
//         ~Restaurant(){}
//         std::string getName(){return name;}
//         std::string getLocation(){return location;}
// };
// class Bakery: public Restaurant{
//     protected:
//         int menu_items;
//         std::string *menu;
//     public:
//         Bakery():Restaurant(){
//             menu_items=0;
//             menu= new std::string[menu_items];
//         }

//         Bakery(int num, std::string view[], std::string n, std::string l): Restaurant(n, l){
//             menu_items=num;
//             menu=new std::string[menu_items];
//             for(int i=0; i<menu_items; i++) menu[i]=view[i];
//         }
//         Bakery(const Bakery& b): Restaurant(b.name, b.location){
//             menu_items=b.menu_items;
//             menu=new std::string[menu_items];
//             for(int i=0;i<menu_items;i++) menu[i]=b.menu[i];
//         }
//         Bakery& operator=(const Bakery& rhs){
//             if(this==&rhs) return *this;
//             delete [] menu;
//             menu_items=rhs.menu_items;
//             menu=new std::string[menu_items];
//             for(int i=0;i<menu_items;i++){
//                 menu[i]=rhs.menu[i];
//             }
//             return *this;
//         }
//         std::string getName(){return this->name;}
//         std::string getLocation(){return this->location;}
//         int getN(){return menu_items;}
//         std::string getM(int i){return menu[i];}
//         ~Bakery(){
//             delete [] menu;
//         }
// };
// }
// int main() {
//     // Creating a Restaurant object
//     using namespace One;
//     Restaurant A;
//     std::cout << "Restaurant name: " << A.getName() << ", Location: " << A.getLocation() << std::endl;
//     Restaurant C("CheeseHouse", "Central and 4th");
//     std::cout << "Restaurant name: " << C.getName() << ", Location: " << C.getLocation() << std::endl;
//     A.operator=(C);
//     std::cout << "Restaurant A is now name: " << A.getName() << ", At Location: " << A.getLocation() <<"\n"<< std::endl;
//     Restaurant G(C);
//     std::cout << "Restaurant G name: " << G.getName() << ", Location: " << G.getLocation() << std::endl;
//     // Creating a Bakery object
//     std::string bakery_menu[] = { "Croissant", "Baguette", "Muffin" };
//     Bakery B(3, bakery_menu, "Bakery X", "Downtown");
//     std::cout << "Bakery name: " << B.getName() << ", Location: " << B.getLocation() << std::endl;
//     std::cout << "Menu items:" << std::endl;
//     for (int i = 0; i < B.getN(); i++) {
//         std::cout << "- " << B.getM(i) << std::endl;
//     }
//     return 0;
// }


// #include <iostream>
// // She will give us class, data members, and a constructor. 
// // We will be asked to write the destructor, copy constructor, 
// // and assignment operation, and we will also need to overload one operation (for example plus). 
// class Sentence{
//     protected:
//         int num;
//         std::string *sentence;
//     public:
//         Sentence(){
//             num=0;
//             sentence=new std::string[num];
//         }
//         Sentence(int n, std::string a[]){
//             num=n;
//             sentence= new std::string[num];
//             for(int i=0;i<num;i++) sentence[i]=a[i];
//         }
//         Sentence(const Sentence& origin){
//             num=origin.num;
//             sentence=new std::string[num];
//             for(int i=0;i<num;i++){ sentence[i]=origin.sentence[i];}
//         }
//         Sentence& operator=(const Sentence& rhs){
//             if(this==&rhs) return *this;
//             delete [] sentence;
//             num=rhs.num;
//             sentence=new std::string[num];
//             for(int i=0;i<num;i++){ sentence[i]=rhs.sentence[i];}
//             return *this;
//         }
//         int getN(){return num;}
//         std::string getSentence(int i){return sentence[i];}
//         int operator%(Sentence b){
//             return num+b.num;
//         }
//         ~Sentence(){
//             delete [] sentence;
//         }
// };
// class SaysWho: public Sentence{
//     protected:
//         std::string name;
//     public:
//         SaysWho(std::string nam){ name=nam;}
//         SaysWho(std::string nam, int numz, std::string sen[]): Sentence(numz, sen){
//             name=nam;
//         }
//         std::string operator%(SaysWho b){ 
//             return name+b.name;
//         }
//         ~SaysWho(){}
// };
// int main(){
//     using namespace std;
//     Sentence one;
//     cout<<one.getSentence(0)<<"  "<<one.getN()<<endl;
//     string var[10]={"hello", "world", "this", "is", "him", "the ", "real", "ol", "double g"};
   
//     Sentence two(10, var);
//     for(int i=0;i<10;i++){cout<<two.getSentence(i)<<endl;}

//     Sentence three(two);
//     cout<<three.getN()<<endl;

//     one.operator=(three);
//     cout<<one.getN()<<endl;

//     cout<<one.operator%(three)<<endl;
//     string zzz[2]={"hello", "world"};
//     SaysWho a("Max", 3, zzz), b("Fro");
//     cout<<a.operator%(b)<<endl;

// }