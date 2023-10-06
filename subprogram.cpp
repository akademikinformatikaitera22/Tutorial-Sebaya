#include<iostream>

using namespace std;

// f(x) = 2*x
int f(int x) {
    return 2 * x;
}

void katakanHalo() {
    cout << "halo temen-temen" << endl;
}

int main() {
    int hasil = f(2);

    cout << hasil << endl;

    katakanHalo();
    return 0;
}