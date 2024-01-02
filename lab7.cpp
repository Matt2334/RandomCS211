#include <iostream>
using namespace std;
void swap(int* x, int* y){
    int temp= *x; 
    *x=*y;
    *y=temp; 
}
int main(){
    int first = 9, second = 1;
    int *p1 = &first, *p2 = &second; //p1=address of first | p2=address of second
    cout << *p1 << " " << *p2<<endl; //prints the dereference of p1 and p2, meaning it will print the value of first and second
    swap(p1, p2); 
    cout << *p1 << " " << *p2<<endl; //prints the dereference of p1 and p2, meaning it will print the values of second and then first. 
    return 0;
}