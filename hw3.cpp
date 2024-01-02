#include <iostream>
using namespace std;
class Creature {
    protected:
        int strength; // How much damage we can inflict
        int hitpoints; // How much damage we can sustain
        virtual string getSpecies(){
            return "nada";
        }
    public:
        Creature(){
            strength=10;
            hitpoints=10;
        }
        Creature(int newStrength, int newHit){
            strength=newStrength;
            hitpoints=newHit;
        };
    
        int getStrength(){return strength;}
        int getHitpoints(){return hitpoints;}
        int setStrength(int S){
            strength=S;
            return strength;
        }
        int setHitpoints(int H){
            hitpoints=H;
            return hitpoints;
        }  

        virtual int getDamage(){
            return 0;
        };
    // Returns amount of damage this creature
    // inflicts in one round of combat
};
class Elf: public Creature{
    public:
        Elf(int newStrength, int newHit): Creature(newStrength, newHit){}
        string getSpecies(){return "Elf";}
        int getDamage(){
            int damage = (rand( ) % strength) + 1;
            cout << getSpecies( ) << " attacks for " << damage << " points!" << endl;
            if ((rand( ) % 10)==0){
                cout << "Magical attack inflicts " << damage<<" additional damage points!" << endl;
                damage = damage * 2;
            }
            return damage;
        }
        
        int getStrength(){return strength;}
        int getHitpoints(){return hitpoints;}
        int setStrength(int S){
            strength=S;
            return strength;
        }
        int setHitpoints(int H){
            hitpoints=H;
            return hitpoints;
        }  
};
class Human: public Creature{
    public:
        Human(int newStrength, int newHit): Creature(newStrength, newHit){}
        string getSpecies(){return "Human";}
        int getDamage(){
            int damage = (rand( ) % strength) + 1;
            cout << getSpecies( ) << " attacks for " << damage << " points!" << endl;   
            return damage;
        }
        
        int getStrength(){return strength;}
        int getHitpoints(){return hitpoints;}
        int setStrength(int S){
            strength=S;
            return strength;
        }
        int setHitpoints(int H){
            hitpoints=H;
            return hitpoints;
        }  
};
class Demon: public Creature{
    public:
        Demon(int newStrength, int newHit): Creature(newStrength, newHit){}
        virtual string getSpecies(){return "Demon";}
        virtual int getDamage(){
            int damage = (rand( ) % strength) + 1;
            cout << getSpecies( ) << " attacks for " << damage << " points!" << endl;
            if ((rand( ) % 100) < 5){
                damage = damage + 50;
                cout << "Demonic attack inflicts 50 "<< "additional damage points!" << endl;
            } 
            return damage;
        }
        
        int getStrength(){return strength;}
        int getHitpoints(){return hitpoints;}
        int setStrength(int S){
            strength=S;
            return strength;
        }
        int setHitpoints(int H){
            hitpoints=H;
            return hitpoints;
        }  
};
class Cyberdemon: public Demon{
    public:
        Cyberdemon(int newStrength, int newHit): Demon(newStrength, newHit){}
        string getSpecies(){return "Cyberdemon";}
       
        int getStrength(){return strength;}
        int getHitpoints(){return hitpoints;}
        int setStrength(int S){
            strength=S;
            return strength;
        }
        int setHitpoints(int H){
            hitpoints=H;
            return hitpoints;
        }  
};
class Balrog: public Demon{
    public:
        Balrog(int newStrength, int newHit): Demon(newStrength, newHit){}
        string getSpecies(){return "Balrog";}
        int getDamage(){
            int damage = (rand( ) % strength) + 1;
            cout << getSpecies( ) << " attacks for " << damage << " points!" << endl;
            if ((rand( ) % 100) < 5){
                damage = damage + 50;
                cout << "Demonic attack inflicts 50 "<< "additional damage points!" << endl;
            } 
            int damage2 = (rand() % strength) + 1;
            cout << "Balrog speed attack inflicts " << damage2 <<" additional damage points!" << endl;
            damage = damage + damage2;
            return damage;
        }
        int getStrength(){return strength;}
        int setStrength(int S){
            strength=S;
            return strength;
        }

        int getHitpoints(){return hitpoints;}
        int setHitpoints(int H){
            hitpoints=H;
            return hitpoints;
        }
};
int main(){
    // strength, hitpoints
    Human hercules(30, 150);
    Elf silver(50, 500);
    Balrog gobo(10, 200);
    Cyberdemon boss(60, 700);
    
    int rounds;
    int damage;
    cout << "how many rounds? ";
    cin >> rounds;
    
    for(int i = 0; i<rounds; i++){
        damage = hercules.getDamage();
        cout << "Hercules attacks gobo the Balrog with " << damage << " damage"<<endl;
        cout << "Gobo's health is "<< gobo.setHitpoints(gobo.getHitpoints() - damage )<<endl;
        
        damage = silver.getDamage();
        cout << "Silver attacks the cyberdemon boss with " << damage << " damage"<<endl;
        cout << "Boss's health is "<< boss.setHitpoints( boss.getHitpoints() - damage )<<endl;
        
        damage = gobo.getDamage();
        
        cout << "Gobo fights back and hits silver with "<< damage << " damage"<<endl;
        cout << "Silver's health is "<< silver.setHitpoints( silver.getHitpoints() - damage)<<endl;
        
        damage = boss.getDamage();
        cout << "Oh no! the cyberdemon hits both the hero Hercules and Silver with "<< damage << " damage!"<<endl;
        cout << "Silver's health is "<< silver.setHitpoints( silver.getHitpoints() - damage )<<endl;
        cout << "Hercules' health is "<< hercules.setHitpoints( hercules.getHitpoints() - damage)<<endl;
        cout<<endl;
    }
    return 0;
}