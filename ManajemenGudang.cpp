#include <iostream>
#include <iomanip>
using namespace std;

struct Barang{
    int id;
    string nama;           
    int stok;
};

struct Node{
    Barang data;    
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(Barang barang) {
        Node* baru = new Node;
        baru->data = barang;
        baru->next = top;
        top = baru;
    }

    void pop() {
        if (isEmpty()) {
            cout << "\nRiwayat kosong !\n";
            return;
        }

        Node* hapus = top;
        top = top->next;

        cout << "\nRiwayat terakhir berhasil dihapus.\n";

        delete hapus;
    }

    void tampil() {
        if (isEmpty()) {
            cout << "\nRiwayat kosong !\n";
            return;
        }

        Node* bantu = top;

        cout << "\n========== RIWAYAT TRANSAKSI ==========\n";

        while (bantu != NULL) {
            cout << "ID Barang : " << bantu->data.id << endl;
            cout << "Nama      : " << bantu->data.nama << endl;
            cout << "Stok      : " << bantu->data.stok << endl;
            cout << "---------------------------------------\n";

            bantu = bantu->next;
        }
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

 
    void enqueue(Barang barang) {

        Node* baru = new Node;
        baru->data = barang;
        baru->next = NULL;

        if (isEmpty()) {
            front = rear = baru;
        } else {
            rear->next = baru;
            rear = baru;
        }

        cout << "\nBarang berhasil ditambahkan !\n";
    }

    void dequeue(Stack &riwayat) {

        if (isEmpty()) {
            cout << "\nGudang kosong!\n";
            return;
        }

        Node* hapus = front;

        riwayat.push(hapus->data);

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        cout << "\nBarang keluar dari gudang!\n";

        delete hapus;
    }

    void tampil() {

        if (isEmpty()) {
            cout << "\nGudang kosong!\n";
            return;
        }

        Node* bantu = front;

        cout << "\n============== DATA GUDANG ==============\n";

        while (bantu != NULL) {

            cout << "ID Barang : " << bantu->data.id << endl;
            cout << "Nama      : " << bantu->data.nama << endl;
            cout << "Stok      : " << bantu->data.stok << endl;
            cout << "-----------------------------------------\n";

            bantu = bantu->next;
        }
    }

int main(){
    
>>>>>>> 04462b212cb3f61cca0f23052d600952ca7abaff
    return 0;
}