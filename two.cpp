// Prompt

// Create a program that manages a student database using vectors and pointers in C++. 
// Define a Student class with private member variables for name, id, and grade. 
// Implement appropriate getter and setter functions to access and modify these private members.

// Utilize a vector to store pointers to Student objects. Include functionalities to add new students to the database, 
// display the details of all students, and find a specific student by their ID. Use dynamic memory allocation 
// to create Student objects and store their pointers in the vector.

// Allow the user to input new student details (name, ID, and grade), store this information in a dynamically 
// allocated Student object, and add its pointer to the vector. Implement a function to display the details of 
// all students by traversing the vector of pointers. Also, create a function to search for a student by ID 
// and display their information.
#include <iostream>
#include <vector>
using namespace std;
class Student{
    private:
        string name;
        int id;
        double grade;
    public:
        Student(){
            name="Uknown";
            id=0;
            grade=0.0;
        }
        Student(string n, int i, double g){
            name=n;
            id=i;
            grade=g;
        }

        string getName(){return name;}
        int getId(){return id;}
        double getGrade(){return grade;}
        
        void setName(string name){
            this->name = name;
        }
        void setId(int id){this->id=id;}
        void setGrade(double g){grade=g;}
        void displayInfo(){
            cout<<"Name: "<<name<<endl;
            cout<<"Id: "<<id<<endl;
            cout<<"Grade: "<<grade<<endl;
        }
};

void Search(vector<Student*> a, int identification){
    for(int i=0;i<a.size();i++){
        if(a[i]->getId()==identification){
            a[i]->displayInfo();
        }
    }
}
int main(){
    vector<Student*> database;
    database.push_back(new Student("Bryan", 1, 98.3));
    Search(database, 1);
    for(int i=0;i<database.size();i++){
        delete database[i];
    }
    database.clear();
    return 0;
}