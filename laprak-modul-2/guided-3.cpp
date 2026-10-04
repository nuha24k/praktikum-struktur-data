#include <iostream>
using namespace std;

void tukarvalue (int x, int y) {
    int temp = x;
    x = y;
    y = temp;
}

void tukarpointer (int *px, int *py) {
    int temp = *px;
    *px = *py;
    *py = temp;
}

void tukarreferensi (int &px, int &py) {
    int temp = px;
    px = py;
    py = temp;
}

int main() {
   int a = 4, b = 6;
   cout << "kondisi awal : a = " << a << ", b = " << b << endl;

    tukarvalue(a, b);
    cout << "kondisi setelah tukar value : a = " << a << ", b = " << b << endl;

    tukarpointer(&a, &b);
    cout << "kondisi setelah tukar pointer : a = " << a << ", b = " << b << endl;

    tukarreferensi(a, b);
    cout << "kondisi setelah tukar referensi : a = " << a << ", b = " << b << endl;

    return 0;
}

