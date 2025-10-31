#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int val) {
        data = val;
        next = NULL;
    }
};

bool isCircular(node* head) {
    if (head == NULL) return false;
    node* temp = head->next;
    while (temp != NULL && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

int main() {
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);

    head->next = second;
    second->next = third;
    third->next = head;  // this makes it circular

    if (isCircular(head))
        cout << "The Linked List is Circular." << endl;
    else
        cout << "The Linked List is Not Circular." << endl;

    return 0;
}

