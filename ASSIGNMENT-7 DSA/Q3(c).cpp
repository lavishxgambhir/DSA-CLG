// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node*left;
    node*right;
    
    node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

node* createTree(){
    node *root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    
    return root;
}

int maxdepth(node*root){
    if(root==NULL) return 0;
    
    int lh=maxdepth(root->left);
    int rh=maxdepth(root->right);
    return 1+max(lh,rh);
}

int main() {
    
    node *root=createTree();
    cout<<maxdepth(root);

    return 0;
}
