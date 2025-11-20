/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
vector<int> v;
    bool isValidBST(TreeNode* root) {
        // our aim is to perform inorder traversal and see if its sorted or not
        inorder(root);
        for(int i=1;i<v.size();i++){
           if(v[i] <= v[i-1] ){
            return false;
           } 
        }
        return true;
    }
    void inorder(TreeNode*root){
        if(root==NULL) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }
};
