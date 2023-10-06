#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

int main() {
    Node *nodeSatu = new Node();
    nodeSatu->data = 5;

    Node nodeDua;
    nodeDua.data = 7;
    nodeDua.next = nodeSatu;

    cout << nodeDua.data << endl;
    cout << nodeDua.next->data << endl;

    return 0;
}