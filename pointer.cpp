#include<iostream>

using namespace std;

void tambah(int *hasil, int a, int b) {
    *hasil = a + b;
}

int main() {
    int x,y,z;
    x = 1;
    y = 3;
    z = 10;
    tambah(&x, y, z);
    cout << x;
    return 0;
}