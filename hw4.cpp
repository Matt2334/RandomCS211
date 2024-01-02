#include <iostream>
using namespace std;
template<typename T>
class DynamicStringArray{
    private:
        int size;
        T *dynamArray;
    public:
        DynamicStringArray(){
            size=0;
            dynamArray=nullptr;
        }
        int getSize(){return size;}
        void addEntry(T z){
            T *dArr = new T[size+1];
            for(int i=0;i<size;i++) dArr[i] = dynamArray[i];
            dArr[size]=z;
            size++;
            delete [] dynamArray;
            dynamArray=dArr;
        }
        bool deleteEntry(T input){
            for(int i=0;i<size;i++){
                if(dynamArray[i]==input){
                    T *deleted= new T[size-1];
                    int count=0;
                    for(int z=0;z<size;z++){
                        if(dynamArray[z]!=input){
                            deleted[count]=dynamArray[z];
                            count++;
                        }
                    }
                    delete [] dynamArray;
                    size--;
                    dynamArray=deleted;
                    return true;
                }
            }
            return false;
        }
        T getEntry(int index){
            if(index>=size){
                cout<<"Error: INDEX OUT OF BOUNDS"<<endl;
            }
            return dynamArray[index];
        }
        DynamicStringArray(DynamicStringArray &origin){
            size=origin.size;
            dynamArray=new T[size];
            for(int i=0;i<size;i++){
                dynamArray[i]=origin.dynamArray[i];
            }
        }

        void operator=(DynamicStringArray& target){
            delete [] target.dynamArray;
            target.size=size;
            target.dynamArray=new T[size];
            for(int i=0;i<size;i++){
                target.dynamArray[i]=dynamArray[i];
            }
        }
        
        ~DynamicStringArray(){ 
            delete [] dynamArray; 
        }
};
int main(){
    DynamicStringArray<int> one;
    one.addEntry(3);
    cout<<"The first entry in a is: "<<one.getEntry(0)<<endl;

    DynamicStringArray<string> two;
    two.addEntry("hello");
    cout<<"The first entry in two is: "<<two.getEntry(0)<<endl;
    
    DynamicStringArray<string> three;
    two.operator=(three);
    cout<<"The first entry in three is: "<<three.getEntry(0)<<endl;
    
    DynamicStringArray<float> four;
    four.addEntry(3.14159);
    four.addEntry(0.618);
    four.addEntry(9.87654321);
    cout<<"The size of four is: "<<four.getSize()<<endl;

    DynamicStringArray<float> five(four);
    for(int i=0;i<five.getSize();i++){
        cout<<five.getEntry(i)<<" ";
    } cout<<endl;
    if(five.deleteEntry(0.618)) cout<<"The new size is: "<<five.getSize()<<endl; 
    for(int i=0;i<five.getSize();i++){
        cout<<five.getEntry(i)<<" ";
    } cout<<endl;

    return 0;
}