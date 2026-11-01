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

address findElm(List L, infotype x) {
    address P = L.first;
    while (P != nullptr) {
        if (P->info == x) {
            return P;
        }
        P = P->next;
    }
    return nullptr;
}

void insertAfter(List &L, address Prec, address P) {
    if (Prec != nullptr && P != nullptr) {
        P->next = Prec->next;
        Prec->next = P;
    }
}

void printList(List L) {
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
    List L;
    createList(L);

    int n;
    if (cin >> n) {
        for (int i = 0; i < n; i++) {
            infotype val;
            cin >> val;
            insertLast(L, alokasi(val));
        }

        infotype cari, baru;
        cin >> cari;
        cin >> baru;

        address Prec = findElm(L, cari);
        if (Prec != nullptr) {
            insertAfter(L, Prec, alokasi(baru));
        }

        printList(L);
    }

    return 0;
}
