#include <iostream>
using namespace std;
class DynamicStringArray{
    private:
        int size;
        string *dynamArray;
    public:
        DynamicStringArray(){
            size=0;
            dynamArray=nullptr;
        }
        
        int getSize(){
            return size;
        }
       
        void addEntry(string z){
            string *dArr = new string[size+1];
            for(int i=0;i<size;i++){
                dArr[i] = dynamArray[i];
            }
            dArr[size]=z;
            size++;
            delete [] dynamArray;
            dynamArray=dArr;
            
        }
        bool deleteEntry(string input){
            for(int i=0;i<size;i++){
                if(dynamArray[i]==input){
                    string *deleted= new string[size-1];
                    for(int z=1;z<size;z++){
                        if(dynamArray[z]!=input) deleted[z-1]=dynamArray[z];
                    }
                    delete [] dynamArray;
                    size--;
                    dynamArray=deleted;
                    return true;
                }
            }
            return false;
        }
        string getEntry(int index){
            if(index>size) return "Error";
            return dynamArray[index];
        }

        DynamicStringArray(DynamicStringArray &origin){
            size=origin.size;
            delete [] dynamArray;
            dynamArray=new string[size];
            for(int i=0;i<size;i++){
                dynamArray[i]=origin.dynamArray[i];
            }
        }

        void operator=(DynamicStringArray& target){
            delete [] target.dynamArray;
            target.size=size;
            target.dynamArray=new string[size];
            for(int i=0;i<size;i++){
                target.dynamArray[i]=dynamArray[i];
            }
        }
        
        ~DynamicStringArray(){ 
            delete [] dynamArray; 
        }
};
int main(){
    DynamicStringArray one;
    one.addEntry("hello");
    cout<<one.getSize()<<endl;
    cout<<"The first entry in one is: "<<one.getEntry(0)<<endl;
    
    DynamicStringArray two;
    one.operator=(two);
    cout<<"The first entry in two is: "<<two.getEntry(0)<<endl;
    
    
    DynamicStringArray three(one);
    three.addEntry("Goodbye");
    cout<<"The first element in three is: "<<three.getEntry(0)<<endl;
    cout<<"The size of three is: "<<three.getSize()<<endl;
    if(three.deleteEntry("hello")){
        cout<<"After deleting the first element in 3 is: "<<three.getEntry(0)<<endl;
        cout<<"The new size is: "<<three.getSize()<<endl;
    }
    return 0;
}