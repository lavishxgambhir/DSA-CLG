#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *head = NULL;

void insBeg(int x) {
    Node *t = new Node{ x, head };
    head = t;
}

void insEnd(int x) {
    Node *t = new Node{ x, NULL };
    if (!head)
        head = t;
    else {
        Node *p = head;
        while (p->next)
            p = p->next;
        p->next = t;
    }
}

void insAfter(int val, int x) {
    Node *p = head;
    while (p && p->data != val)
        p = p->next;
    if (!p) return;
    Node *t = new Node{ x, p->next };
    p->next = t;
}

void insBefore(int val, int x) {
    if (!head) return;
    if (head->data == val) {
        insBeg(x);
        return;
    }
    Node *p = head;
    while (p->next && p->next->data != val)
        p = p->next;
    if (!p->next) return;
    Node *t = new Node{ x, p->next };
    p->next = t;
}

void delBeg() {
    if (!head) return;
    Node *t = head;
    head = head->next;
    delete t;
}

void delEnd() {
    if (!head) return;
    if (!head->next) {
        delete head;
        head = NULL;
        return;
    }
    Node *p = head;
    while (p->next->next)
        p = p->next;
    delete p->next;
    p->next = NULL;
}

void delVal(int val) {
    if (!head) return;
    if (head->data == val) {
        delBeg();
        return;
    }
    Node *p = head;
    while (p->next && p->next->data != val)
        p = p->next;
    if (!p->next) return;
    Node *t = p->next;
    p->next = t->next;
    delete t;
}

void search(int val) {
    Node *p = head;
    int pos = 1;
    while (p) {
        if (p->data == val) {
            cout << "Found at position " << pos << endl;
            return;
        }
        p = p->next;
        pos++;
    }
    cout << "Not found\n";
}

void display() {
    Node *p = head;
    while (p) {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int main() {
    int ch, x, v;
    while (true) {
        cout << "\n1. Insert at Beginning"
             << "\n2. Insert at End"
             << "\n3. Insert Before a Value"
             << "\n4. Insert After a Value"
             << "\n5. Delete from Beginning"
             << "\n6. Delete from End"
             << "\n7. Delete a Specific Node"
             << "\n8. Search for a Node"
             << "\n9. Display All Nodes"
             << "\n0. Exit"
             << "\n\nChoice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter value: ";
                cin >> x;
                insBeg(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                insEnd(x);
                break;

            case 3:
                cout << "Insert before which value? ";
                cin >> v;
                cout << "Enter new value: ";
                cin >> x;
                insBefore(v, x);
                break;

            case 4:
                cout << "Insert after which value? ";
                cin >> v;
                cout << "Enter new value: ";
                cin >> x;
                insAfter(v, x);
                break;

            case 5:
                delBeg();
                break;

            case 6:
                delEnd();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> x;
                delVal(x);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> x;
                search(x);
                break;

            case 9:
                display();
                break;

            case 0:
                return 0;
        }
    }
}

