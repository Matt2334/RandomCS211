#include <iostream>
using namespace std;
double convertToMPH(int minutes, int seconds){return (60/(minutes+(seconds/100.0)));}
double convertToMPH(double kph){return kph/1.61;}
int main(){
    int min, sec;
    double kph;
    cout<<"Input how many minutes per mile: "; cin>>min;
    cout<<"Input the additional seconds per mile: "; cin>>sec;
    cout<<convertToMPH(min, sec)<<" miles per hour"<<endl;
    cout<<"Enter your Kilometers per hour speed: "; cin>>kph;
    cout<<convertToMPH(kph)<<endl;
    return 0;
}