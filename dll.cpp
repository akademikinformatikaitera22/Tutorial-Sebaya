#include<iostream>

using namespace std;

typedef struct Node* address;

struct Node{
    int data; // utk menyimpan nilai
    address next; // utk merujuk gerbong selanjutnya
    address prev; // utk merujuk gerbong sebelumnya
};

struct List{
    address first; // utk menyimpan gerbong terdepan
    address last; // utk menyimpan gerbong terbelakang
};

// fungsi yg bertujuan untuk membuat list baru yang kosong / NULL
void createEmpty(List *L) {
    (*L).first = NULL;
    (*L).last = NULL;
}

// utk mengecek apakah gerbong x itu ada atau tidak 
bool isEmpty(address x) {
    if (x == NULL) {
        return true;
    } else {
        return false;
    }
}

address allocation(int n) {
    address newNode = new Node();
    newNode->data = n;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void deallocation(address x) {
    delete x;
}

void addFirst(int n, List *L) {
    address newNode = allocation(n);

    if(isEmpty((*L).first)) {
        (*L).first = newNode;
        (*L).last = newNode;
        return;
    } 

    newNode->next = (*L).first;
    (*L).first->prev = newNode;
    (*L).first = newNode;
}

void printListFirst(List list) {
    address current = list.first;

    while(current != NULL) {
        cout << current->data << "->";
        current = current->next;
    }

    cout << "NULL" << endl;
}

void printListLast(List list) {
    address current = list.last;

    while(current != NULL) {
        cout << current->data << "->";
        current = current->prev;
    }

    cout << "NULL" << endl;
}


int main() {
    List myList; // NULL
    createEmpty(&myList);

    addFirst(5, &myList);
    addFirst(10, &myList);

    printListFirst(myList);
    printListLast(myList);

    return 0;
}