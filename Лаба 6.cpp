#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

struct Books {
    Books(string _title, string _author, int _release, int _price): title{_title}, author{_author}, release{_release}, price{_price} {}
    
    string title;
    string author;
    
    int release;
    int price;
};

vector<Books> getBooksByAuthor(vector<Books> book, string author){
    vector<Books> result;
    
    for (Books a : book){
        if (a.author == author){
            result.push_back(a);
        }
    }
    return result;
}

vector<Books> getBooks(string path){
    vector<Books> result;
    fstream file(path);
    
    if (file.is_open()){
        string title, author;
        int release, price;
        while (file >> title >> author >> release >> price){
            result.push_back(Books(title, author, release, price));
        }
    }
    file.close();
    return result;
}

int main(){
    
    int summ = 0; 
    int c = 1;
    int oldBook = 10000;
    
    string name_author = "";
    string old_book = "";
    string path = "book.txt";
    
    cout << "Введите автора: "; cin >> name_author;
    cout << endl;
    cout << "Книги автора: " << name_author << endl;
    
    vector<Books> book;
    book = getBooks(path);
    
    for (Books a : getBooksByAuthor(book, name_author)){
        cout << c << ") " << a.title << endl;
        summ = summ + a.price;
        c++;
        if (a.release < oldBook){
            oldBook = a.release;
        }
        if (a.release == oldBook){
        old_book = a.title;
        }
    }
    
    cout << endl;
    cout << "Общая стоимость: " << summ << endl;
    cout << "Самая старая книга: " << old_book << endl;
}

