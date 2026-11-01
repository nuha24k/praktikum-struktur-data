#include "Doublylist.h"

int main() {
    List L;
    CreateList(L);

    /* ===== Soal 1: input data kendaraan ===== */
    char lagi = 'y';
    while (lagi == 'y' || lagi == 'Y') {
        infotype x;
        cout << "masukkan nomor polisi: ";
        cin >> x.nopol;

        // cek nopol sudah terdaftar atau belum
        if (findElm(L, x) != Nil) {
            cout << "nomor polisi sudah terdaftar" << endl;
        } else {
            cout << "masukkan warna kendaraan: ";
            cin >> x.warna;
            cout << "masukkan tahun kendaraan: ";
            cin >> x.thnBuat;
            insertLast(L, alokasi(x));
        }
        cout << "tambah data lagi? (y/n): ";
        cin >> lagi;
        cout << endl;
    }
    printInfo(L);

    /* ===== Soal 2: cari nopol D001 ===== */
    infotype cari;
    cari.nopol = "D001";
    address P = findElm(L, cari);
    cout << "Masukkan Nomor Polisi yang dicari : " << cari.nopol << endl;
    if (P != Nil) {
        cout << "Nomor Polisi : " << P->info.nopol   << endl;
        cout << "Warna        : " << P->info.warna   << endl;
        cout << "Tahun        : " << P->info.thnBuat << endl;
    } else {
        cout << "Data tidak ditemukan" << endl;
    }

    /* ===== Soal 3: hapus nopol D003 ===== */
    cari.nopol = "D003";
    cout << "\nMasukkan Nomor Polisi yang akan dihapus : " << cari.nopol << endl;
    P = findElm(L, cari);
    if (P == Nil) {
        cout << "Data tidak ditemukan" << endl;
    } else {
        address hapus = Nil;
        if (P == L.First) {
            deleteFirst(L, hapus);
        } else if (P == L.Last) {
            deleteLast(L, hapus);
        } else {
            deleteAfter(P->prev, hapus);
        }
        cout << "Data dengan nomor polisi " << hapus->info.nopol
             << " berhasil dihapus." << endl;
        dealokasi(hapus);
    }
    printInfo(L);

    return 0;
}