#include <iostream>
class MyInteger{
    private: 
        int value;
    public: 
        MyInteger(){
            value=173856;
        }
        int operator[](int index) const{
            std::string v = std::to_string(value);
            for(int i=0; i<v.length();i++){
                if(i==index){return (v[i]-'0');}
            }
            return -1;
        }
        friend int operator+(const MyInteger& x,const MyInteger& y);
        friend int operator-(const MyInteger& x,const MyInteger& y);
};
int operator+(const MyInteger& x, const MyInteger& y){
    return x[1]+y[2];
}
int operator-(const MyInteger& x, const MyInteger& y){
    return x[1]-y[0];
}
int main(){
    MyInteger one, two;
    std::cout<<"The value of one at index 4 is: "<<one[4]<<std::endl;
    std::cout<<"The value of two at index 3 is: "<<two[3]<<std::endl;

    std::cout<<"one at index 1("<<one[1]<<") + two at index 2("<<two[2]<<") is: "<<one+two<<std::endl;
    std::cout<<"one at index 1("<<one[1]<<") - two at index 0("<<two[0]<<") is: "<<one-two<<std::endl;
    return 0;
};