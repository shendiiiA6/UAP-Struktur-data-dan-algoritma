#include <iostream>
#include <iomanip>
using namespace std;

struct Barang{
    int id;
    string nama;       //struct
    int stok;
};

struct Node{
    Barang data;    //pointer
    Node* next;
};


int main(){
    cout << "Hello World";
    return 0;
}