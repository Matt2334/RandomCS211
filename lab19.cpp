#include <iostream>
class Vehicle{
    public:
        std::string company;
        int cylinders;
        std::string owner;
        Vehicle(){
            company="";
            cylinders=0;
            owner="";
        }
        Vehicle(std::string brand, int cyl, std::string holder){
            company=brand;
            cylinders=cyl;
            owner=holder;
        }
        std::string getCompany()const{
            return company;
        }
        int getCyl()const{
            return cylinders;
        }
        std::string getOwner()const{
            return owner;
        }
        // assignment operator=
        Vehicle& operator=(const Vehicle& other){
            if(this == &other){return *this;}
            this->company=other.getCompany();
            this->owner=other.getOwner();
            this->cylinders=other.getCyl();
            return *this;
        }

        // copy constructor
        Vehicle(const Vehicle &other){
            company=other.getCompany();
            owner=other.getOwner();
            cylinders=other.getCyl();
        }
        void printSpecs(){
            std::cout<<"Company: "<<company<<" | Owner: "<<owner<<" | Cylinders: "<<cylinders<<std::endl;
        }
};
class Truck: public Vehicle{
    public:
        double load_capacity;
        int towing_capacity;
        Truck(){
            load_capacity=0.0;
            towing_capacity=0;
        }
        double getLC()const{
            return load_capacity;
        }
        int getTC()const{
            return towing_capacity;
        }
        // assignment operator=
        Truck& operator=(const Truck& other){
            if(this == &other){return *this;}
            this->load_capacity = other.getLC();
            this->towing_capacity = other.getTC();
            return *this;
        }
        Truck(std::string b, int c, std::string o, double lc, int tc): Vehicle(b, c, o){
            load_capacity=lc;
            towing_capacity=tc;
        }

        // copy constructor
        Truck(const Truck &t){
            if(!t.company.empty()){
                company=t.getCompany();
                owner=t.getOwner();
                cylinders=t.getCyl();
            }
            load_capacity = t.getLC();
            towing_capacity = t.getTC();
        }

        Truck(double lc, int tc){
            load_capacity = lc;
            towing_capacity = tc;
        }
        void printInfo(){
            if(!company.empty()){
                std::cout<<"Company: "<<company<<" | Owner: "<<owner<<" | Cylinders: "<<cylinders<<" | Load Capacity: "<<load_capacity<<" | Towing Capacity: "<<towing_capacity<<std::endl;
            }
            else{
                std::cout<<"Load Capacity: "<<load_capacity<<" | Towing Capacity: "<<towing_capacity<<std::endl;
            }
        }
};
int main(){
    Vehicle cx50, tyc("Toyota", 2, "Max"), three(tyc) ; //Uses default constructor for cx50 var. 
    cx50.printSpecs();
    tyc.printSpecs();
    cx50.operator=(tyc);
    std::cout<<std::endl;
    std::cout<<"The cx50 is reassigned to ";
    cx50.printSpecs();
    three.printSpecs();
    
    std::cout<<std::endl;
    Truck f150("Ford", 4, "Tom", 3.325, 14), abc, b2w(f150);
    f150.printInfo();
    abc.printInfo();
    b2w.printInfo();

    std::cout<<"Truck b2w is now reasigned to the values of abc: ";
    b2w.operator=(abc);
    b2w.printInfo();
    return 0;
}