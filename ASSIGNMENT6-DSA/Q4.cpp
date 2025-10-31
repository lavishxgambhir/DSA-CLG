#include <iostream>
#include <string>
using namespace std;

class node {
public:
    char data;
    node* next;
    node* back;

    node(char val) {
        data = val;
        next = NULL;
        back = NULL;
    }
};

node* createDLL(string s) {
    if (s.empty()) return NULL;
    node* head = new node(s[0]);
    node* prev = head;
    for (int i = 1; i < s.size(); i++) {
        node* temp = new node(s[i]);
        prev->next = temp;
        temp->back = prev;
        prev = temp;
    }
    return head;
}

bool isPalindrome(node* head) {
    if (head == NULL || head->next == NULL) return true;
    node* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
    while (head != tail && tail->next != head) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->back;
    }
    return true;
}

int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    node* head = createDLL(s);
    if (isPalindrome(head))
        cout << "The Doubly Linked List is a Palindrome." << endl;
    else
        cout << "The Doubly Linked List is not a Palindrome." << endl;
    return 0;
}

