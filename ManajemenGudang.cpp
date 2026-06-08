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
            cout << "\nGudang kosong !\n";
            return;
        }

        Node* hapus = front;

        riwayat.push(hapus->data);

        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        cout << "\nBarang keluar dari gudang !\n";

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
    Queue gudang;
    Stack riwayat;

    int pilihan;

    do {

        cout << "\n=====================================" << endl;
        cout << "        SISTEM MANAJEMEN GUDANG" << endl;
        cout << "=====================================" << endl;
        cout << "1. Tambah Barang" << endl;
        cout << "2. Barang Keluar" << endl;
        cout << "3. Tampilkan Data Gudang" << endl;
        cout << "4. Tampilkan Riwayat" << endl;
        cout << "5. Hapus Riwayat Terakhir" << endl;
        cout << "6. Sorting Stok Ascending" << endl;
        cout << "7. Sorting Nama A-Z" << endl;
        cout << "8. Keluar" << endl;
        cout << "=====================================" << endl;
        cout << "Pilih Menu : ";
        cin >> pilihan;

        switch (pilihan) {

        case 1: {

            Barang barang;

            cout << "\nInput ID Barang   : ";
            cin >> barang.id;

            cin.ignore();

            cout << "Input Nama Barang : ";
            getline(cin, barang.nama);

            cout << "Input Stok        : ";
            cin >> barang.stok;

            gudang.enqueue(barang);

            break;
        }

        case 2:
            gudang.dequeue(riwayat);
            break;

        case 3:
            gudang.tampil();
            break;

        case 4:
            riwayat.tampil();
            break;

        case 5:
            riwayat.pop();
            break;

        case 6:
            gudang.sortStokAscending();
            break;

        case 7:
            gudang.sortNamaAscending();
            break;

        case 8:
            cout << "\nProgram selesai." << endl;
            break;

        default:
            cout << "\nMenu tidak tersedia !" << endl;
        }

    } while (pilihan != 8);

    return 0;
}