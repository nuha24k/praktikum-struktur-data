#include <iostream>
using namespace std;

// Prosedur menukar nilai dua variabel dan mengalikan hasilnya dengan 10 menggunakan Pass by Reference
void tukarDanKalikan(int &a, int &b) {
    int temp = a;
    a = b * 10;
    b = temp * 10;
}

int main() {
    int x, y;
    cin >> x >> y;

    tukarDanKalikan(x, y);

    cout << "x = " << x << ", y = " << y << endl;

    return 0;
}
