//Prompt: 

// Create a program that manages a library system using pointers in C++. 
// Define a Book class with private member variables for title, author, and ISBN. 
// Implement appropriate getter and setter functions to access and modify these private members.

// Utilize pointers to create a dynamic collection of Book objects. 
// Allow functionalities to add new books to the library, display details of all books, 
// and find a specific book by its title or ISBN. Use dynamic memory allocation to create Book 
// objects and store their pointers.

// Enable the user to input details (title, author, ISBN) for new books and store this 
// information in dynamically allocated Book objects. Add these book objects' pointers to your 
// dynamic collection. Implement a function to display the details of all books by traversing 
// the collection of pointers. Additionally, create functions to search for a book by its title
// or ISBN and display its information.

#include <iostream>
using namespace std;
class Book{
    private:
        string title;
        string author;
        string ISBN;
    public:
        Book(): title("Unkown"), author("Unknown"), ISBN("Unregistered"){}
        Book(string t, string a, string id){
            title=t; 
            author=a;
            ISBN=id;
        }
        void setTitle(string t){title=t;}
        void setAuthor(string a){author=a;}
        void setISBN(string id){ISBN=id;}

        string getTitle(){return title;}
        string getAuthor(){return author;}
        string getISBN(){return ISBN;}
};
void libraryDetails(Book *a[], int size){
    for(int i=0;i<size;i++){
        cout<<a[i]->getTitle()<<", "<<a[i]->getAuthor()<<", "<<a[i]->getISBN()<<endl;
    }
}
// void Search(Book *a[],int size, string search_title){
//     for(int i=0;i<size;i++){
//         if(a[i]->getTitle()==search_title){
//             cout<<a[i]->getTitle()<<", "<<a[i]->getAuthor()<<", "<<a[i]->getISBN()<<endl;
//         }
//     }
// }
void Search(Book *a[], int size, string id){
    for(int i=0;i<size;i++){
        if(a[i]->getISBN()==id){
            cout<<a[i]->getTitle()<<", "<<a[i]->getAuthor()<<", "<<a[i]->getISBN()<<endl;
        }
    }
}

int main(){
    Book *library[100];
    library[0] = new Book();
    library[1] = new Book("Sea Of Serpents", "Rick Riordan", "1552424X");
    library[2]=new Book();
    libraryDetails(library, 3);
    cout<<endl;

    Search(library,3, "1552424X");
    return 0;
}
