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
            cout << "\nRiwayat kosong !" << endl;
            return;
        }

        Node* hapus = top;
        top = top->next;

        cout << "\nRiwayat terakhir berhasil dihapus." << endl;

        delete hapus;
    }

    void tampil() {
        if (isEmpty()) {
            cout << "\nRiwayat kosong !" << endl;
            return;
        }

        Node* bantu = top;

        cout << "\n========== RIWAYAT TRANSAKSI ==========" << endl;

        while (bantu != NULL) {
            cout << "ID Barang : " << bantu->data.id << endl;
            cout << "Nama      : " << bantu->data.nama << endl;
            cout << "Stok      : " << bantu->data.stok << endl;
            cout << "---------------------------------------" << endl;

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

        cout << "\nBarang berhasil ditambahkan !" << endl;
    }

    void dequeue(Stack &riwayat) {

        if (isEmpty()) {
            cout << "\nGudang kosong !" << endl;
            return;
        }

        Node* hapus = front;

        riwayat.push(hapus->data);

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        cout << "\nBarang keluar dari gudang !" << endl;

        delete hapus;
    }

    void tampil() {

        if (isEmpty()) {
            cout << "\nGudang kosong!\n";
            return;
        }

        Node* bantu = front;

        cout << "\n============== DATA GUDANG ==============" << endl;

        while (bantu != NULL) {

            cout << "ID Barang : " << bantu->data.id << endl;
            cout << "Nama      : " << bantu->data.nama << endl;
            cout << "Stok      : " << bantu->data.stok << endl;
            cout << "-----------------------------------------" << endl;

            bantu = bantu->next;
        }
    }

     void sortStokAscending() {

        if (front == NULL) {
            cout << "\nData kosong!\n";
            return;
        }

        bool tukar;
        Node* ptr;

        do {
            tukar = false;
            ptr = front;

            while (ptr->next != NULL) {

                if (ptr->data.stok > ptr->next->data.stok) {

                    Barang temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;

                    tukar = true;
                }

                ptr = ptr->next;
            }

        } while (tukar);

        cout << "\nData berhasil diurutkan berdasarkan stok (Ascending).\n";
    }

     void sortNamaAscending() {

        if (front == NULL) {
            cout << "\nData kosong!\n";
            return;
        }

        bool tukar;
        Node* ptr;

        do {
            tukar = false;
            ptr = front;

            while (ptr->next != NULL) {

                if (ptr->data.nama > ptr->next->data.nama) {

                    Barang temp = ptr->data;
                    ptr->data = ptr->next->data;
                    ptr->next->data = temp;

                    tukar = true;
                }

                ptr = ptr->next;
            }

        } while (tukar);

        cout << "\nData berhasil diurutkan berdasarkan nama (A-Z).\n";
    }
};

int main(){
    
    return 0;
}