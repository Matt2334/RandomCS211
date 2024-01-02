#include <iostream>
using namespace std;
class Number{
    private:
        int n;
    public:
        void setN(int value) { n = value;}
        int getN(){ return n;}
        int reverseN(int n, int result=0){ 
            if(n<10 &&result==0) return n;
            else{
                if(n==0 &&result!=0) return result;
                int last = n%10;
                return reverseN(n/10, result*10+last);
            }
        }
};
int main(){
    Number n;
    n.setN(1234);
    cout<<"This is the input value: "<<n.getN()<<endl;
    cout<<"This is the reversed value: "<<n.reverseN(n.getN())<<endl;
}