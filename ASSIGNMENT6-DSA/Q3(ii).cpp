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
    node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        node* temp = new node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    prev->next = head;
    return head;
}

int findSize(node* head) {
    if (head == NULL) return 0;
    int count = 1;
    node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    vector<int> arr = {5, 10, 15, 20, 25};
    node* head = createCLL(arr);
    int size = findSize(head);
    cout << "Size of Circular Linked List: " << size << endl;
    return 0;
}

