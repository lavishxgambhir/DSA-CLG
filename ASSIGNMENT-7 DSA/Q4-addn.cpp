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
vector<int> ans;
    vector<int> rightSideView(TreeNode* root) {
        rightSIDE(root,0);
        return ans;
    }
    void rightSIDE(TreeNode*root,int level){
        if(root==NULL) return;

        if(ans.size()==level){
            ans.push_back(root->val);
        }

        if(root->right){
            rightSIDE(root->right,level+1);
        }
        if(root->left){
            rightSIDE(root->left,level+1);
        }
    }
    
};
