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
    int height(TreeNode* root, int& flag){
        if(root==nullptr) return 1;
        int left = height(root->left, flag);
        int right = height(root->right, flag);
        int diff = abs(left-right);
        
        if(diff>1) flag =0;
        // else flag= 0;
        
        return max(left,right)+1;        
    } 
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;
        int flag = 1;
        height(root, flag);
        return flag;        
    }
};
