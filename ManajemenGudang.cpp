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


int main(){
    
    return 0;
}