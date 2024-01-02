#include <iostream>
using namespace std;
void swap(char* x, char* y){
    char temp= *x; 
    *x=*y;
    *y=temp; 
}
int main(){
    string ins;
    cout<<"Enter in a string: ";
    cin>>ins;
    char *first=&ins[0], *last;
    int j=0;
    while(ins[j]!='\0'){j++;}
    last=&ins[j-1];
    for(int i=0;i<j/2;i++){
        swap(first, last);
        first++;
        last--;
    }
    cout<<ins<<endl;
    return 0;

}
