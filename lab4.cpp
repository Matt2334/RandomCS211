#include <iostream>
using namespace std;
int main(){
    for(int i=1; i<=15; i++){
        if(i%2==0){ 
            if(i%2==0 && i%3==0){
                if(i%2==0 && i%3==0 && i%5==0){
                    cout<<i<<" is divisible by 2 and 3 and 5"<<endl;
                }
                else cout<<i<<" is divisible by 2 and 3"<<endl;
            }
            else cout<<i<<" is divisible by 2"<<endl;
        }
    }
    return 0;
}