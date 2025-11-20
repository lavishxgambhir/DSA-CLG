#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* left;
    node* right;

    node(int value) {
        data = value;
        left = NULL;
        right = NULL;
    }
};

node* createBST() {
    node* root = new node(50);
    root->left = new node(30);
    root->right = new node(70);
    root->left->left = new node(20);
    root->left->right = new node(40);
    root->right->left = new node(60);
    root->right->right = new node(80);

    return root;
}

node* InsertNodeBST(node*root,int val){
    if(root==NULL){
        return NULL;
    }
    node*curr=root;
    while(true){
        if(curr->data<val){
            if(curr->right!=NULL){
                curr=curr->right;
            }
            else{
                node* newnode=new node(val);
                curr->right=newnode;
                break;
            }
        }
        else{
            if(curr->left!=NULL){
                curr=curr->left;
            }
            else{
                node* newnode=new node(val);
                curr->left=newnode;
                break;
            }
        }
    }
    return root;
    
}

void inorder(node*root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(node*root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void preorder(node *root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}



int main() {
    node* root = createBST();
    InsertNodeBST(root,15);
    inorder(root);
    
    cout<<endl<<endl;
    
    postorder(root);
    
    cout<<endl<<endl;
    
    preorder(root);

    return 0;
}

