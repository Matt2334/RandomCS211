#include <iostream>
using namespace std;
class Student{
    protected:
        double gpa;
        string f_sport;
        int id;
    public:
        Student(){
            gpa=0.0;
            f_sport="soccer";
            id=0;
        }
        Student(double g, string fs, int i){
            gpa=g;
            f_sport=fs;
            id=i;
        }
        Student(const Student &orig){
            gpa=orig.gpa;
            f_sport=orig.f_sport;
            id=orig.id;
        }
        double getGPA(){return gpa;}
        string getFS(){return f_sport;}
        int getID(){return id;}

        void setGPA(double g){gpa=g;}
        void setFS(string fs){f_sport=fs;}
        void setID(int i){id=i;}

        Student& operator=(const Student &rhs){
            if(this==&rhs) return *this;
            gpa=rhs.gpa;
            f_sport=rhs.f_sport;
            id=rhs.id;
            return *this;
        }
        ~Student(){}
};
int main() {
    // Creating instances of the Student class using various constructors
    Student student1; // Default constructor
    Student student2(3.5, "tennis", 12345); // Parameterized constructor

    // Displaying information using getter functions
    cout << "Student 1 GPA: " << student1.getGPA() << endl;
    cout << "Student 1 Favorite Sport: " << student1.getFS() << endl;
    cout << "Student 1 ID: " << student1.getID() << endl;

    cout << "Student 2 GPA: " << student2.getGPA() << endl;
    cout << "Student 2 Favorite Sport: " << student2.getFS() << endl;
    cout << "Student 2 ID: " << student2.getID() << endl;

    // Testing assignment operator and copy constructor
    Student student3 = student2; // Using copy constructor
    Student student4;
    student4 = student1; // Using assignment operator

    // Displaying information to verify copy constructor and assignment operator
    cout << "Student 3 GPA: " << student3.getGPA() << endl;
    cout << "Student 3 Favorite Sport: " << student3.getFS() << endl;
    cout << "Student 3 ID: " << student3.getID() << endl;

    cout << "Student 4 GPA: " << student4.getGPA() << endl;
    cout << "Student 4 Favorite Sport: " << student4.getFS() << endl;
    cout << "Student 4 ID: " << student4.getID() << endl;

    return 0;
}
