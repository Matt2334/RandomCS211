#include <iostream>
using namespace std;
class HalalCart{
    private:
        int cart_id;
        int total_platters_sold;
        static int all_sales;
    public:
        HalalCart(int CID, int TPS){
            cart_id= CID;
            total_platters_sold=TPS;
            all_sales+=TPS;
        }
        void justSold(){
            total_platters_sold++;
            all_sales++;
        }
        int getSold(){
            return total_platters_sold;
        }
        static int allSold(){
            return all_sales;
        }
};
int HalalCart::all_sales=0;
int main(){
    int n;
    HalalCart shah(111, 3);
    HalalCart b2b(112, 15);
    HalalCart jos(113, 7);
    cout << "Shah sold: "<<shah.getSold( )<<endl;
    shah.justSold();
    cout<<"Shah just sold another, the new total sold is: "<<shah.getSold()<<endl;

    cout << "how many platters did the jos cart sell during the lunchtime rush? ";
    cin >> n;
    for(int i = 0; i < n; i++){
        jos.justSold( );
    }
    cout<<"Shah + B2B + Jos = "<<shah.getSold()+b2b.getSold()+jos.getSold()<<endl;
    cout<<shah.getSold()<<"  "<<b2b.getSold()<<"  "<<jos.getSold()<<endl;
    cout << "Total sold so far: "<< HalalCart::allSold( )<<endl;
    return 0;
}
