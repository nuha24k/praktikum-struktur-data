#include "Doublylist.h"

/* Membuat list kosong */
void CreateList(List &L) {
    L.First = Nil;
    L.Last  = Nil;
}

/* Alokasi elemen baru berisi x */
address alokasi(infotype x) {
    address P = new ElmList;
    P->info = x;
    P->next = Nil;
    P->prev = Nil;
    return P;
}

/* Dealokasi elemen P */
void dealokasi(address &P) {
    delete P;
    P = Nil;
}

/* Menampilkan seluruh isi list */
void printInfo(List L) {
    address P = L.First;
    cout << "\nDATA LIST 1" << endl;
    if (P == Nil) {
        cout << "(list kosong)" << endl;
        return;
    }
    while (P != Nil) {
        cout << "no polisi : " << P->info.nopol   << endl;
        cout << "warna     : " << P->info.warna   << endl;
        cout << "tahun     : " << P->info.thnBuat << endl;
        cout << endl;
        P = P->next;
    }
}

/* Insert elemen P di akhir list */
void insertLast(List &L, address P) {
    if (L.First == Nil) {          // list kosong
        L.First = P;
        L.Last  = P;
    } else {
        P->prev = L.Last;
        (L.Last)->next = P;
        L.Last = P;
    }
}

/* Mencari elemen berdasarkan nomor polisi (x.nopol) */
address findElm(List L, infotype x) {
    address P = L.First;
    while (P != Nil) {
        if (P->info.nopol == x.nopol) {
            return P;
        }
        P = P->next;
    }
    return Nil;
}

/* Hapus elemen pertama, hasilnya di P */
void deleteFirst(List &L, address &P) {
    P = L.First;
    if (P == Nil) return;
    if (L.First == L.Last) {       // hanya satu elemen
        L.First = Nil;
        L.Last  = Nil;
    } else {
        L.First = (L.First)->next;
        (L.First)->prev = Nil;
        P->next = Nil;
    }
}

/* Hapus elemen terakhir, hasilnya di P */
void deleteLast(List &L, address &P) {
    P = L.Last;
    if (P == Nil) return;
    if (L.First == L.Last) {       // hanya satu elemen
        L.First = Nil;
        L.Last  = Nil;
    } else {
        L.Last = (L.Last)->prev;
        (L.Last)->next = Nil;
        P->prev = Nil;
    }
}

/* Hapus elemen setelah Prec, hasilnya di P.
   Syarat: Prec != Nil dan Prec->next bukan elemen terakhir
   (kalau elemen terakhir gunakan deleteLast). */
void deleteAfter(address Prec, address &P) {
    P = Nil;
    if (Prec == Nil || Prec->next == Nil) return;
    P = Prec->next;
    Prec->next = P->next;
    if (P->next != Nil) {
        (P->next)->prev = Prec;
    }
    P->next = Nil;
    P->prev = Nil;
}