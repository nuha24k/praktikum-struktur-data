#include <iostream>
#include <string>

using namespace std;

// Definisi Tipe Data Singly Linked List
typedef string infotype;
typedef struct elmlist *address;

struct elmlist {
    infotype info;
    address next;
};

struct List {
    address first;
};

// Primitif Singly Linked List
void createList(List &L) {
    L.first = nullptr;
}

address alokasi(infotype x) {
    address P = new elmlist;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(address &P) {
    delete P;
    P = nullptr;
}

bool isEmpty(List L) {
    return L.first == nullptr;
}

void insertLast(List &L, address P) {
    if (isEmpty(L)) {
        L.first = P;
    } else {
        address Q = L.first;
        while (Q->next != nullptr) {
            Q = Q->next;
        }
        Q->next = P;
    }
}

void deleteFirst(List &L, address &P) {
    if (isEmpty(L)) {
        P = nullptr;
    } else {
        P = L.first;
        L.first = L.first->next;
        P->next = nullptr;
    }
}

void printAntrean(List L) {
    cout << "Antrean: ";
    if (isEmpty(L)) {
        cout << "(kosong)" << endl;
        return;
    }
    address P = L.first;
    while (P != nullptr) {
        cout << P->info;
        if (P->next != nullptr) {
            cout << " -> ";
        }
        P = P->next;
    }
    cout << endl;
}

int main() {
    List antrean;
    createList(antrean);

    int menu;
    while (cin >> menu) {
        if (menu == 1) {
            string nama;
            cin >> ws;
            getline(cin, nama);
            address P = alokasi(nama);
            insertLast(antrean, P);
            printAntrean(antrean);
        } else if (menu == 2) {
            address P = nullptr;
            deleteFirst(antrean, P);
            if (P != nullptr) {
                cout << "Melayani: " << P->info << endl;
                dealokasi(P);
            } else {
                cout << "Antrean kosong, tidak ada nasabah yang dapat dilayani." << endl;
            }
            printAntrean(antrean);
        } else if (menu == 3) {
            break;
        }
    }

    return 0;
}
