#include <iostream>
#include <string>

using namespace std;

string konversiTerbilang(int n) {
    string satuan[] = {
        "nol", "satu", "dua", "tiga", "empat", 
        "lima", "enam", "tujuh", "delapan", "sembilan", 
        "sepuluh", "sebelas"
    };

    if (n < 0 || n > 100) {
        return "Angka di luar rentang (0 - 100)";
    } else if (n <= 11) {
        return satuan[n];
    } else if (n < 20) {
        return satuan[n - 10] + " belas";
    } else if (n < 100) {
        int puluhan = n / 10;
        int sisa = n % 10;
        if (sisa == 0) {
            return satuan[puluhan] + " puluh";
        } else {
            return satuan[puluhan] + " puluh " + satuan[sisa];
        }
    } else { 
        return "seratus";
    }
}

int main() {
    int angka;

    cout << "=== PROGRAM KONVERSI ANGKA KE TULISAN (0 - 100) ===" << endl;
    cout << "Masukkan angka (0 - 100): ";
    cin >> angka;

    if (angka >= 0 && angka <= 100) {
        cout << angka << " : " << konversiTerbilang(angka) << endl;
    } else {
        cout << "Error: Masukkan angka bulat positif antara 0 sampai 100!" << endl;
    }

    return 0;
}

