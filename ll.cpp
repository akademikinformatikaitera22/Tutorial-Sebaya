#include<iostream>

using namespace std;

typedef struct Node* LL;

struct Node {
    int value;
    Node* next;
};

Node* createEmpty() {
    Node* emptyNode = new Node(); // alokasi
    return emptyNode;
}

void addAfter(int n, LL* head) {
    Node* nodeNew = createEmpty();
    nodeNew->value = n;

    if(*head == NULL) {
        *head = nodeNew;
        return;
    }

    nodeNew->next = (*head)->next;
    (*head)->next = nodeNew;
}

void addBefore(int n, LL* head) {
    Node* nodeNew = createEmpty();
    nodeNew->value = n;

    if(*head == NULL) {
        *head = nodeNew;
        return;
    }

    nodeNew->next = *head;
    *head = nodeNew;
}

void addTail(int n, LL* head) {
    Node* nodeNew = createEmpty();
    nodeNew->value = n;

    if(*head == NULL) {
        *head = nodeNew;
        return;
    }

    Node* current = *head;

    while(current->next != NULL) {
        current = current->next;
    }

    current->next = nodeNew;
}

void printLL(Node* head) {
    Node* current = head;
    
    while(current != NULL) {
        cout << current->value << " ";
        current = current->next;
    }

    cout << endl;
}

int main() {
    Node* head = NULL;
    addAfter(5, &head);
    addAfter(10, &head);
    addAfter(3, &head);
    addBefore(11, &head);
    addTail(100, &head);
    printLL(head);

    return 0;
}