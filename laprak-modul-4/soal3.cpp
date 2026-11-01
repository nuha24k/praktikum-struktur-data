#include <iostream>

using namespace std;

// Definisi Tipe Data Singly Linked List
typedef int infotype;
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

// Prosedur untuk menghitung jumlah total (sum) dari seluruh elemen
void hitungTotal(List L, int &total) {
    total = 0;
    address P = L.first;
    while (P != nullptr) {
        total += P->info;
        P = P->next;
    }
}

int main() {
    List L;
    createList(L);

    int n;
    if (cin >> n) {
        for (int i = 0; i < n; i++) {
            infotype val;
            cin >> val;
            insertLast(L, alokasi(val));
        }

        int total = 0;
        hitungTotal(L, total);

        cout << total << endl;
    }

    return 0;
}
