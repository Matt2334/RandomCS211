#include <iostream>
#include <fstream>
#include <stack>
using namespace std;
void copyLine(ifstream &fin, ofstream &fout){
    string line;
    stack<char> open_p;
    while (getline(fin, line)){
        for (int i = 0; i < line.length(); i++)
        {
            if (open_p.empty()){
                open_p.push(line[i]);
            }
            else if ((open_p.top() == '(' && line[i] == ')')){
                open_p.pop();
            }
            else{
                open_p.push(line[i]);
            }
        }
        if (open_p.empty())
            fout << "true" << endl;
        else
            fout << "false" << endl;
        open_p = stack<char>();
    }
}
int main(){
    ifstream fin;
    ofstream fout;
    fin.open("expressions.txt");
    fout.open("result.txt");
    copyLine(fin, fout);
    return 0;
}
