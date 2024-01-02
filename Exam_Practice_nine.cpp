#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    cout<<"Enter the numbers, enter 0 to stop: ";
    cin>>n;
    if(n==0) return 0;
    vector<int> evens;
    vector<int> odds;
    while(n!=0){
        cin>>n;
        if(n==0) break;
        if(n%2==1) odds.push_back(n);
        else evens.push_back(n);
    }
    cout<<"Evens: ";
    for(int i=0;i<evens.size();i++){
        cout<<evens[i]<<" ";
    }cout<<endl;

    cout<<"Odds: ";
    for(int i=0;i<odds.size();i++){
        cout<<odds[i]<<" ";
    }cout<<endl;

    return 0;
    
}
