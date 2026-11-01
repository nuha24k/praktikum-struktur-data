#include <iostream>
#include "titik.h"

using namespace std; 

int main() {
    Titik tA, tB; 

    cout << "input Titik Pertama" << endl;
    inputTitik(tA); 

    cout << "input Titik Kedua" << endl;
    inputTitik(tB); 

    cout << "\n hasil rekap koordinat: " << endl;
    tampilTitik(tA); 
    tampilTitik(tB); 
    
    float jarak = hitungJarak(tA, tB); 
    cout << "jarak Antara Kedua Titik: " << jarak << endl;

    return 0;
}