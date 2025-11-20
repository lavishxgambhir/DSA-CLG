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


node*searchNON_RECURSIVE(node*root,int val){
    if(root==NULL) return NULL;
    while(root!=NULL && root->data==val){
        root=root->data<val ? root->right : root->left;
    }
    return root;
}

node* search_RECURSIVE(node*root,int val){
    if(root==NULL) return NULL;
    if(root->data==val) return root;
    if(root->data<val){
        search_RECURSIVE(root->right,val);
    }
    if(root->data>val){
        search_RECURSIVE(root->left,val);
    }
    return root;
}

node* MAXBST(node*root){
    if(root==NULL) return NULL;
    while(root->right){
        root=root->right;
    }
    cout<<root->data;
    return root;
}

node *minBST(node*root){
    if(root==NULL) return NULL;
    while(root->left){
        root=root->left;
    }
    cout<<root->data;
    return root;
}

int maxdepthBST(node*root){
    if(root==NULL) return 0;
    
    int lh=maxdepthBST(root->left);
    int rh=maxdepthBST(root->right);
    
    return 1+max(lh,rh);
}

node* inorderSUCCESSOR(node*root,node*p){
    node* successor=NULL;
    
    while(root!=NULL){
        if(root==NULL) return NULL;
        
        if(root->data<=p->data){
        root=root->right;
    }
    else{
        successor=root;
        root=root->left;
    }
        
    }
    cout<<successor->data<<" ";
    return successor;
    
}

node*inorderPredecessor(node*root,node*p){
    node*predecessor=NULL;
    
    while(root){
        if(root==NULL) return NULL;
        if(root->data<=p->data){
            predecessor=root;
            root=root->right;
        }
        else{
            root=root->left;
        }
        
    }
    cout<<predecessor->data<<" "<<endl;
    return predecessor;
}


int main() {
    node* root = createBST();
    InsertNodeBST(root,15);
    inorder(root);
    
    cout<<endl<<endl;
    
    postorder(root);
    
    cout<<endl<<endl;
    
    preorder(root);
    
    cout<<endl<<endl;
    
    node*p=searchNON_RECURSIVE(root,60);
    search_RECURSIVE(root,120);
    
    cout<<"max of bst is: ";
    MAXBST(root);
    
    cout<<endl<<endl;
    
    cout<<"min of bst is: ";
    minBST(root);
    
    cout<<endl<<endl;
    
    cout<<"maxdepth of bst is: ";
    cout<<maxdepthBST(root);
    
    cout<<endl<<endl;
    
    cout<<"inorder successor of 60 is: ";
    node* successor=inorderSUCCESSOR(root,p);
    
    cout<<endl;
    
    cout<<"predecessor of 60 is: ";
    node*predecessor=inorderPredecessor(root,p);
    
    return 0;
}
