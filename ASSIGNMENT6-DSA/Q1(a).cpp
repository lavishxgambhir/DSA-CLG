#include <iostream>
#include <vector>
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

node* createCLL(vector<int> &arr) {
    if (arr.empty()) return NULL;
    node* head = new node(arr[0]);
    node* tail = head;
    for (int i = 1; i < arr.size(); i++) {
        node* temp = new node(arr[i]);
        tail->next = temp;
        tail = temp;
    }
    tail->next = head;
    return head;
}

void print(node* head) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    node* temp = head;
    cout << "List: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << "\n";
}

node* insertHead(node* head, int val) {
    node* newNode = new node(val);
    if (!head) {
        newNode->next = newNode;
        return newNode;
    }
    node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
    return head;
}

node* insertEnd(node* head, int val) {
    node* newNode = new node(val);
    if (!head) {
        newNode->next = newNode;
        return newNode;
    }
    node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    temp->next = newNode;
    newNode->next = head;
    return head;
}

node* insertKth(node* head, int k, int val) {
    node* newNode = new node(val);
    if (!head) {
        newNode->next = newNode;
        return newNode;
    }
    if (k == 1)
        return insertHead(head, val);

    node* temp = head;
    int count = 1;
    while (temp->next != head && count < k - 1) {
        temp = temp->next;
        count++;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

node* deleteHead(node* head) {
    if (!head) return NULL;
    if (head->next == head) {
        delete head;
        return NULL;
    }
    node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    node* del = head;
    temp->next = head->next;
    head = head->next;
    delete del;
    return head;
}

node* deleteEnd(node* head) {
    if (!head) return NULL;
    if (head->next == head) {
        delete head;
        return NULL;
    }
    node* temp = head;
    while (temp->next->next != head)
        temp = temp->next;
    node* del = temp->next;
    temp->next = head;
    delete del;
    return head;
}

node* deleteKth(node* head, int k) {
    if (!head) return NULL;
    if (k == 1)
        return deleteHead(head);
    node* temp = head;
    int count = 1;
    while (temp->next != head && count < k - 1) {
        temp = temp->next;
        count++;
    }
    if (temp->next == head)
        return head;
    node* del = temp->next;
    temp->next = del->next;
    delete del;
    return head;
}

void searchElement(node* head, int val) {
    if (!head) {
        cout << "List is empty\n";
        return;
    }
    node* temp = head;
    bool found = false;
    do {
        if (temp->data == val) {
            cout << "Value " << val << " found at position " << "\n";
            found = true;
            break;
        }
        temp = temp->next;
    } while (temp != head);
    if (!found)
        cout << "Value " << val << " not found in the list.\n";
}

int main() {
    vector<int> arr = {3, 4, 7, 2, 5};
    node* head = createCLL(arr);
    int choice, val, k;

    do {
        cout << "1. Print List\n";
        cout << "2. Insert at Head\n";
        cout << "3. Insert at End\n";
        cout << "4. Insert at Kth Position\n";
        cout << "5. Delete Head\n";
        cout << "6. Delete End\n";
        cout << "7. Delete Kth Node\n";
        cout << "8. Search Element\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                print(head);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                head = insertHead(head, val);
                break;
            case 3:
                cout << "Enter value: ";
                cin >> val;
                head = insertEnd(head, val);
                break;
            case 4:
                cout << "Enter position and value: ";
                cin >> k >> val;
                head = insertKth(head, k, val);
                break;
            case 5:
                head = deleteHead(head);
                break;
            case 6:
                head = deleteEnd(head);
                break;
            case 7:
                cout << "Enter position: ";
                cin >> k;
                head = deleteKth(head, k);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                searchElement(head, val);
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

