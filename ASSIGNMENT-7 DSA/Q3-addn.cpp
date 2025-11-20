#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;
    node(int data) {
        this->data = data;
        left = right = nullptr;
    }
};

int maxDepth(node* root) {
    if (!root) return 0;
    int lh = maxDepth(root->left);
    int rh = maxDepth(root->right);
    return 1 + max(lh, rh);
}

int main() {
    node* root = new node(12);
    root->left = new node(5);
    root->right = new node(18);
    root->left->left = new node(2);
    root->left->right = new node(9);
    root->right->right = new node(25);
    root->left->right->left = new node(7);
    root->left->right->right = new node(11);
    root->right->right->left = new node(22);

    cout << maxDepth(root);
    return 0;
}

