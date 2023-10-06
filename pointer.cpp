#include<iostream>

using namespace std;

int main() {
    int x,y,z;
    x = 1;
    y = 3;
    z = 10;

    int *px;
    px = &y;

    x = 2;
    y = 5;
    z = 11;

    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    cout << *px << endl;
    return 0;
}