#include <iostream>
using namespace std;
class Student{
    private:
        string name;
        int numClasses;
        string *classList= 0;
    public:
        Student(){
            name="noname";
            numClasses=0;
        }
        Student(string name, int numClasses) {
        this->name = name;
        this->numClasses = numClasses;
        classList = new string[numClasses];
        }
        Student(const Student& g){
            name=g.name;
            numClasses=g.numClasses;
            classList=new string[numClasses];
            for(int i=0;i<numClasses;i++){
                classList[i]=g.classList[i];
            }
        }
        // mutator
        void setName(string name){this->name=name;}
        void setNumClasses(int numClasses){this->numClasses=numClasses;}
        void addElement(string className, int index){classList[index]=className;}
        
        // accessor
        string getName(){return name;}
        int getNumClasses(){return numClasses;}
        string *getClassList(){return classList;}

        // destructor
        ~Student()
        {
            delete [] classList;
        }
};
int main()
{
    Student one= Student();
    cout<<one.getName()<<endl;
    one.setName("Kim");
    cout<<one.getName()<<endl;
    cout<<one.getNumClasses()<<endl;
    one.setNumClasses(1);
    cout<<one.getNumClasses()<<endl;
    cout<<one.getClassList()<<endl;
    cout<<endl;

    Student two=Student("Brian", 3);
    cout<<two.getName()<<endl;
    two.addElement("Science", 0);
    two.addElement("Math", 1);
    two.addElement("English", 2);
    string* classes=two.getClassList();
    for(int i=0;i<two.getNumClasses();i++){
        cout<<classes[i]<<" ";
    }
    cout<<endl;
    cout<<endl;

    Student three(two);
    for(int i=0;i<two.getNumClasses();i++){
        cout<<classes[i]<<" ";
    }cout<<endl;
    cout<<three.getName()<<endl;
    three.setName("Jay");
    cout<<three.getName()<<endl;
}
