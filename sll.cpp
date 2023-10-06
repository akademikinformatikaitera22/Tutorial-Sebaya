#include<iostream>

using namespace std;

typedef struct Node* address;

struct Node{
    int data; // utk menyimpan nilai
    address next; // utk merujuk gerbong selanjutnya
};

struct List{
    address first; // utk menyimpan gerbong terdepan
};

// fungsi yg bertujuan untuk membuat list baru yang kosong / NULL
void createEmpty(List *L) {
    (*L).first = NULL;
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
    return newNode;
}

void deallocation(address x) {
    delete x;
}

void addAfter(int n, List *L) {
    address newNode = allocation(n);

    if(isEmpty((*L).first)) {
        (*L).first = newNode;
        return;
    } 

    newNode->next = (*L).first->next;
    (*L).first->next = newNode;
}

void addBefore(int n, List *L) {
    address newNode = allocation(n);

    if(isEmpty((*L).first)) {
        (*L).first = newNode;
        return;
    } 

    newNode->next = (*L).first;
    (*L).first = newNode;
}

void addTail(int n, List *L) {
    address newNode = allocation(n);

    if(isEmpty((*L).first)) {
        (*L).first = newNode;
        return;
    } 

    address current = (*L).first;

    while (current->next != NULL){
        current = current->next;
    }

    current->next = newNode;
}

void deleteFirst(List *L) {
    if((*L).first != NULL) {
        address tmp = (*L).first;
        (*L).first = (*L).first->next;
        deallocation(tmp);
    }
}

void deleteData(int n, List *L) {
    if((*L).first != NULL) {
        address current = (*L).first;
        address prev;
        
        while (current != NULL && current->data != n) {
            prev = current;
            current = current->next;
        }
        
        if(current != NULL) {
            prev->next = current->next;
            delete current;
            cout << "Data " << n << " berhasil dihapus!" << endl;
        } else {
            cout << "Data " << n << " tidak ada di list!" << endl;
        }
    }
}

void printList(List list) {
    address current = list.first;

    while(current != NULL) {
        cout << current->data << "->";
        current = current->next;
    }

    cout << "NULL" << endl;
}


int main() {
    List myList; // NULL
    createEmpty(&myList);

    addAfter(5, &myList);
    addAfter(7, &myList);
    addAfter(1, &myList);
    addBefore(9, &myList);
    addTail(13, &myList);
    deleteFirst(&myList);
    deleteData(7, &myList);

    printList(myList);

    return 0;
}