#include <iostream>
#include <string>
using namespace std;

int hitungKemunculanKarakter(const string &kata, char target) {
    int jumlah = 0;
    for (char c : kata) {
        if (c == target) {
            jumlah++;
        }
    }
    return jumlah;
}

int main() {
    string kata;
    char target;

    cin >> kata;
    cin >> target;

    cout << hitungKemunculanKarakter(kata, target) << endl;

    return 0;
}
