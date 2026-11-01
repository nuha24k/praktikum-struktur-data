#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Struktur data buku
struct Buku {
    string judul;
    int tahunTerbit;
};

// Definisi Tipe Data Singly Linked List
typedef Buku infotype;
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

void deleteLast(List &L, address &P) {
    if (isEmpty(L)) {
        P = nullptr;
    } else if (L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    } else {
        address Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void printList(List L) {
    cout << "Daftar Buku:" << endl;
    address P = L.first;
    while (P != nullptr) {
        cout << P->info.judul << " (" << P->info.tahunTerbit << ")" << endl;
        P = P->next;
    }
}

// Fungsi bantu untuk membersihkan spasi di awal dan akhir string
static void trim(string &s) {
    while (!s.empty() && isspace((unsigned char)s.back())) {
        s.pop_back();
    }
    while (!s.empty() && isspace((unsigned char)s.front())) {
        s.erase(s.begin());
    }
}

// Fungsi bantu untuk mem-parsing baris menjadi judul dan tahun terbit
static bool parseBuku(const string &s, Buku &b) {
    size_t lastSpace = s.find_last_of(" \t");
    if (lastSpace == string::npos) return false;

    string title = s.substr(0, lastSpace);
    string yearStr = s.substr(lastSpace + 1);

    trim(title);
    trim(yearStr);

    if (yearStr.empty()) return false;
    for (char c : yearStr) {
        if (!isdigit((unsigned char)c)) return false;
    }

    b.judul = title;
    b.tahunTerbit = stoi(yearStr);
    return true;
}

int main() {
    List L;
    createList(L);

    string line;
    if (!getline(cin, line)) {
        return 0;
    }

    trim(line);
    if (line.empty()) {
        return 0;
    }

    // Periksa apakah baris pertama berupa bilangan bulat N
    bool isOnlyDigits = true;
    for (char c : line) {
        if (!isdigit((unsigned char)c)) {
            isOnlyDigits = false;
            break;
        }
    }

    if (isOnlyDigits) {
        int n = stoi(line);
        for (int i = 0; i < n; i++) {
            if (getline(cin, line)) {
                trim(line);
                if (line.empty()) {
                    i--;
                    continue;
                }
                Buku b;
                if (parseBuku(line, b)) {
                    insertLast(L, alokasi(b));
                }
            }
        }
    } else {
        // Baris pertama sudah merupakan data buku
        Buku b;
        if (parseBuku(line, b)) {
            insertLast(L, alokasi(b));
        }
        while (getline(cin, line)) {
            trim(line);
            if (line.empty()) break;
            if (parseBuku(line, b)) {
                insertLast(L, alokasi(b));
            }
        }
    }

    // Menjalankan satu kali operasi penghapusan data buku terakhir
    address pDel = nullptr;
    deleteLast(L, pDel);
    if (pDel != nullptr) {
        dealokasi(pDel);
    }

    // Menampilkan daftar buku yang tersisa
    printList(L);

    return 0;
}
