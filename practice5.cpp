#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> responses;
    int month=0;
    while(month!=-1){
        cout<<"Enter a value between 1 and 12: ";
        cin>>month;
        if(month>0 && month<13) responses.push_back(month);
        switch(month){
            case 1: 
                cout<<"January"<<endl;
                break;
            case 2: 
                cout<<"February"<<endl;
                break;
            case 3: 
                cout<<"March"<<endl;
                break;
            case 4: 
                cout<<"April"<<endl;
                break;
            case 5: 
                cout<<"May"<<endl;
                break;
            case 6: 
                cout<<"June"<<endl;
                break;
            case 7: 
                cout<<"July"<<endl;
                break;
            case 8: 
                cout<<"August"<<endl;
                break;
            case 9: 
                cout<<"September"<<endl;
                break;
            case 10: 
                cout<<"October"<<endl;
                break;
            case 11:
                cout<<"November"<<endl;
                break;
            case 12: 
                cout<<"December"<<endl;
                break;
            default: 
                cout<<"Make sure your value is between 1 and 12"<<endl;
        }
    }
    for(int x=0; x<=responses.size(); x++){cout<<responses[x]<<endl;}
}
