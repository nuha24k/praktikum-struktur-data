#include <iostream>
using namespace std;

int main() {
    int nilai1D[3] = {80, 85, 90};

    cout << "Array 1 DImensi" << endl;

    cout << "Nilai 1: " << nilai1D[0] << endl;
    cout << "Nilai 2: " << nilai1D[1] << endl;
    cout << "Nilai 3: " << nilai1D[2] << endl;

    int nilai2D[2][3] = {{80, 85, 90}, {75, 80, 85}};

    cout << "Array 2 DImensi" << endl;

    cout << "Nilai [0][0]: " << nilai2D[0][0] << endl;
    cout << "Nilai [0][1]: " << nilai2D[0][1] << endl;
    cout << "Nilai [0][2]: " << nilai2D[0][2] << endl;
    cout << "Nilai [1][0]: " << nilai2D[1][0] << endl;
    cout << "Nilai [1][1]: " << nilai2D[1][1] << endl;
    cout << "Nilai [1][2]: " << nilai2D[1][2] << endl;

    int nilai3D[2][2][3] = {
        {{80, 85, 90}, {75, 80, 85}},
        {{70, 75, 80}, {65, 70, 75}}
    };

    cout << "Array 3 DImensi" << endl;
    
    cout << "Nilai [0][0][0]: " << nilai3D[0][0][0] << endl;
    cout << "Nilai [0][0][1]: " << nilai3D[0][0][1] << endl;
    cout << "Nilai [0][0][2]: " << nilai3D[0][0][2] << endl;
    cout << "Nilai [0][1][0]: " << nilai3D[0][1][0] << endl;
    cout << "Nilai [0][1][1]: " << nilai3D[0][1][1] << endl;
    cout << "Nilai [0][1][2]: " << nilai3D[0][1][2] << endl;
    cout << "Nilai [1][0][0]: " << nilai3D[1][0][0] << endl;
    cout << "Nilai [1][0][1]: " << nilai3D[1][0][1] << endl;    
    cout << "Nilai [1][0][2]: " << nilai3D[1][0][2] << endl;
    cout << "Nilai [1][1][0]: " << nilai3D[1][1][0] << endl;
    cout << "Nilai [1][1][1]: " << nilai3D[1][1][1] << endl;
    cout << "Nilai [1][1][2]: " << nilai3D[1][1][2] << endl;


}