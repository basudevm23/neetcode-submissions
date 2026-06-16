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
    void checking(TreeNode* root,long long low, long long high, int& flag){
        if(root==nullptr || flag ==0) return;
        if(root->val<=low || root->val >= high){
            flag = 0;
            return;
        }
        checking(root->left, low, root->val, flag);
        checking(root->right, root->val, high, flag);
    }
    bool isValidBST(TreeNode* root) {
        // all values in the left subtree should be lower than the root, and all values in the right sub tree should be higher than the root
        // so a range is set for both of them
        
        if(root==nullptr) return true;
        int flag = 1;
        checking(root,LLONG_MIN, LLONG_MAX, flag);
        return flag;        
    }
};
