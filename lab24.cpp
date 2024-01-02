#include <iostream>
template <class T>
class Set{
    private:
        int size;
        T *array;
    public:
        Set(){
            size=0;
            array = new T[size];
        }
        Set(T arr[], int s){
            size=0;
            array = new T[s];
            for(int i=0;i<s;i++){
                bool test=false;
                for(int z=0;z<size;z++){
                    if(arr[i]==array[z]){
                        test=true;
                        break;
                    }
                }
                if(!test){
                    array[size]=arr[i];
                    size++;
                }
            }
        }
        void addElement(T element){
            for(int i=0;i<size;i++){
                if(array[i]==element) return;
            }
            T *newArr = new T[size+1];
            for(int z=0;z<=size;z++) newArr[z]=array[z];
            newArr[size]=element;
            delete[] array;
            array=newArr;
            size++;
        
        }
        int getSize(){return size;}
        void printArr(){
            for(int i=0;i<size;i++){
                std::cout<<array[i]<<" ";
            }std::cout<<std::endl;
        }
        T* getArray(){return array;}

        // not needed since the user is responsible to delete the array;
        // ~Set(){delete array;}

};
int main(){
    int a[] = {1, 2, 2, 3, 4, 2};
    Set<int> mySet(a, 6);
    mySet.printArr();
    mySet.addElement(2);
    mySet.addElement(5);
    mySet.printArr();
    std::cout<<"The number of items in the set is: "<<mySet.getSize()<<std::endl;
    int* mySetArray = mySet.getArray();

    for(int i=0; i<mySet.getSize();i++){
        std::cout<<mySetArray[i]<<" ";
    }std::cout<<std::endl;

    delete[] mySetArray;
    return 0;
}