#include <iostream>
using namespace std;

int main() {
    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    int* nilai = new int[n];
    int total = 0;

    for (int i = 0; i < n; i++) {
        cin >> nilai[i];
        total += nilai[i];
    }

    // Rata-rata dibulatkan ke bawah menjadi integer
    int rataRata = total / n;

    int diAtasRataRata = 0;
    for (int i = 0; i < n; i++) {
        if (nilai[i] > rataRata) {
            diAtasRataRata++;
        }
    }

    cout << "Rata-rata: " << rataRata << endl;
    cout << "Di atas rata-rata: " << diAtasRataRata << endl;

    delete[] nilai;
    return 0;
}
