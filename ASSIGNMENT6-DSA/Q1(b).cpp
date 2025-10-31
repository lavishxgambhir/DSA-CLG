#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node* next;
    node* back;

    node(int val) {
        data = val;
        next = NULL;
        back = NULL;
    }
};

node* convertArrToDLL(vector<int> &arr) {
    if (arr.empty()) return NULL;
    node* head = new node(arr[0]);
    node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        node* temp = new node(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(node* head) {
    node* temp = head;
    cout << "List: ";
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

node* insertHead(node* head, int value) {
    node* newHead = new node(value);
    if (head) {
        newHead->next = head;
        head->back = newHead;
    }
    return newHead;
}

node* insertBeforeTail(node* head, int value) {
    if (head == NULL || head->next == NULL)
        return insertHead(head, value);
    node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    node* prev = temp->back;
    node* newNode = new node(value);
    newNode->next = temp;
    newNode->back = prev;
    prev->next = newNode;
    temp->back = newNode;
    return head;
}

node* insertBeforeKthNode(node* head, int k, int value) {
    if (head == NULL || k <= 1)
        return insertHead(head, value);
    node* temp = head;
    int count = 1;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }
    if (!temp) {
        node* tail = head;
        while (tail->next)
            tail = tail->next;
        node* newNode = new node(value);
        tail->next = newNode;
        newNode->back = tail;
        return head;
    }
    node* prev = temp->back;
    node* newNode = new node(value);
    newNode->next = temp;
    newNode->back = prev;
    if (prev) prev->next = newNode;
    temp->back = newNode;
    return head;
}

node* deleteHead(node* head) {
    if (!head) return NULL;
    node* temp = head;
    head = head->next;
    if (head) head->back = NULL;
    delete temp;
    return head;
}

node* deleteEnd(node* head) {
    if (!head || !head->next) return deleteHead(head);
    node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->back->next = NULL;
    delete temp;
    return head;
}

node* deleteKthNode(node* head, int k) {
    if (!head) return NULL;
    if (k == 1) return deleteHead(head);
    node* temp = head;
    int count = 1;
    while (temp && count < k) {
        temp = temp->next;
        count++;
    }
    if (!temp) return head;
    if (!temp->next) return deleteEnd(head);
    node* prev = temp->back;
    node* front = temp->next;
    prev->next = front;
    front->back = prev;
    delete temp;
    return head;
}

void searchElement(node* head, int value) {
    node* temp = head;
    int pos = 1;
    bool found = false;
    while (temp) {
        if (temp->data == value) {
            cout << "Value " << value << " found at position " << pos << "\n";
            found = true;
            break;
        }
        temp = temp->next;
        pos++;
    }
    if (!found)
        cout << "Value " << value << " not found in the list.\n";
}

int main() {
    vector<int> arr = {3, 4, 7, 2, 5};
    node* head = convertArrToDLL(arr);
    int choice, val, k;

    do {
        cout << "1. Print List\n";
        cout << "2. Insert at Head\n";
        cout << "3. Insert Before Tail\n";
        cout << "4. Insert Before Kth Node\n";
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
                head = insertBeforeTail(head, val);
                break;
            case 4:
                cout << "Enter position and value: ";
                cin >> k >> val;
                head = insertBeforeKthNode(head, k, val);
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
                head = deleteKthNode(head, k);
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

