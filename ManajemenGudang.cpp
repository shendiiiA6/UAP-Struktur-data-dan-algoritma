#include <iostream>
#include <iomanip>
using namespace std;

struct Barang{
    int id;
    string nama;       //materi struct
    int stok;
};

struct Node{
    Barang data;    //materi pointer
    Node* next;
};




int main(){
    cout << "Hello World";
    return 0;
}