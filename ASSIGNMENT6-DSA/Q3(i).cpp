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

node* createDLL(vector<int> &arr) {
    if (arr.empty()) return NULL;
    node* head = new node(arr[0]);
    node* prev = head;
    for (int i = 1; i < arr.size(); i++) {
        node* temp = new node(arr[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

int findSize(node* head) {
    int count = 0;
    node* temp = head;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    node* head = createDLL(arr);
    int size = findSize(head);
    cout << "Size of Doubly Linked List: " << size << endl;
    return 0;
}

