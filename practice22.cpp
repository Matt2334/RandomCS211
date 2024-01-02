#include <iostream>
#include <cstdlib>
using namespace std;

class Dice{
    public:
        Dice(){
            numSides = 6;
            srand(time(NULL)); 
        }
        Dice(int numSides){
            this->numSides = numSides;
            srand(time(NULL)); 
        }
        virtual int rollDice() const{
            return (rand() % numSides) + 1;
        }
    protected:
        int numSides;
};
class LoadedDice: public Dice{
    public:
        LoadedDice(): Dice(){}
        LoadedDice(int numSides):Dice(numSides){}
        int rollDice() const override{
            int chance = rand() % 100;
            if (chance >=51){
                return numSides;
            }
            else{
                return (rand() % numSides) + 1;
            }
        }
};

int rollTwoDice(const Dice &die1, const Dice &die2){
  return die1.rollDice() + die2.rollDice();
}

int main(){
  LoadedDice a(6);
  LoadedDice b(6);

  double sum = 0;
  for (int i = 0; i < 10; i++){
    cout<<"Sum: "<<rollTwoDice(a, b)<<endl;
  }
  cout<<endl;
  return 0;
}
