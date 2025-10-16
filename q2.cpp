#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL, *tail = NULL;

void insertEnd(int value) {
    Node *temp = new Node{ value, NULL };
    if (!head) head = tail = temp;
    else {
        tail->next = temp;
        tail = temp;
    }
}

int deleteKey(int key) {
    int count = 0;
    while (head && head->data == key) {
        Node *temp = head;
        head = head->next;
        delete temp;
        count++;
    }
    Node *curr = head;
    while (curr && curr->next) {
        if (curr->next->data == key) {
            Node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
            count++;
        } else curr = curr->next;
    }
    return count;
}

void display() {
    Node *p = head;
    while (p) {
        cout << p->data;
        if (p->next) cout << "->";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int n, x, key;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(x);
    }
    cin >> key;
    cout << "Count: " << deleteKey(key) << " , Updated Linked List: ";
    display();
}

