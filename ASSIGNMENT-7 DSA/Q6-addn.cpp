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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        map<int,int>mapp;

        for(int i=0;i<inorder.size();i++){
            mapp[inorder[i]]=i;
        }
        TreeNode*root=buildtree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mapp);
        return root;
    }
    TreeNode* buildtree(vector<int>&inorder,int instart,int inend,vector<int>&postorder,int poststart,int postend,map<int,int>&mapp){

        if(poststart>postend || instart>inend){
            return NULL;
        }

        TreeNode*root=new TreeNode(postorder[postend]);
        
        int inRoot=mapp[root->val];
        int numsleft=inRoot-instart;

        root->left=buildtree(inorder,instart,inRoot-1,postorder,poststart,poststart+numsleft-1,mapp);
        root->right=buildtree(inorder,inRoot+1,inend,postorder,poststart+numsleft,postend-1,mapp);
        return root;
    }
};
