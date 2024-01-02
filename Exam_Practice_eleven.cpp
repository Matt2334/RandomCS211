// #include <iostream>
// // She will give us class, data members, and a constructor. 
// // We will be asked to write the destructor, copy constructor, 
// // and assignment operation, and we will also need to overload one operation (for example plus). 
// class Sentence{
//     protected:
//         int num;
//         std::string *sentence;
//     public:
//         Sentence(){
//             num=0;
//             sentence=new std::string[num];
//         }
//         Sentence(int n, std::string a[]){
//             num=n;
//             sentence= new std::string[num];
//             for(int i=0;i<num;i++) sentence[i]=a[i];
//         }
//         Sentence(const Sentence& origin){
//             num=origin.num;
//             sentence=new std::string[num];
//             for(int i=0;i<num;i++){ sentence[i]=origin.sentence[i];}
//         }
//         Sentence& operator=(const Sentence& rhs){
//             if(this==&rhs) return *this;
//             delete [] sentence;
//             num=rhs.num;
//             sentence=new std::string[num];
//             for(int i=0;i<num;i++){ sentence[i]=rhs.sentence[i];}
//             return *this;
//         }
//         int getN(){return num;}
//         std::string getSentence(int i){return sentence[i];}
//         int operator%(Sentence b){
//             return num+b.num;
//         }
//         ~Sentence(){
//             delete [] sentence;
//         }
// };
// class SaysWho: public Sentence{
//     protected:
//         std::string name;
//     public:
//         SaysWho(std::string nam){ name=nam;}
//         SaysWho(std::string nam, int numz, std::string sen[]): Sentence(numz, sen){
//             name=nam;
//         }
//         std::string operator%(SaysWho b){ 
//             return name+b.name;
//         }
//         ~SaysWho(){}
// };
// int main(){
//     using namespace std;
//     Sentence one;
//     cout<<one.getSentence(0)<<"  "<<one.getN()<<endl;
//     string var[10]={"hello", "world", "this", "is", "him", "the ", "real", "ol", "double g"};
   
//     Sentence two(10, var);
//     for(int i=0;i<10;i++){cout<<two.getSentence(i)<<endl;}

//     Sentence three(two);
//     cout<<three.getN()<<endl;

//     one.operator=(three);
//     cout<<one.getN()<<endl;

//     cout<<one.operator%(three)<<endl;
//     string zzz[2]={"hello", "world"};
//     SaysWho a("Max", 3, zzz), b("Fro");
//     cout<<a.operator%(b)<<endl;

// }
