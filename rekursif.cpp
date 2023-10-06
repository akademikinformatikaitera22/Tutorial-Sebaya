#include<iostream>

using namespace std;

void rekursif(int a) {
    if(a >= 0) {
        cout << a << endl;
        rekursif(a - 1);
    }
}

int main() {
    rekursif(10);
    return 0;
}