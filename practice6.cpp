#include <iostream>
#include <fstream> 
using namespace std;
void copyLine(ifstream& fin, ofstream& fout){
    char next;
    do{
       fin.get(next);
       fout<<next;
    }while(next !='\n' && fin.eof()==false);
}
int main(){
    ifstream fin;
    ofstream fout;
    fin.open("stuff.txt");
    fout.open("stuff_copy.txt");
    copyLine(fin,fout);
}
