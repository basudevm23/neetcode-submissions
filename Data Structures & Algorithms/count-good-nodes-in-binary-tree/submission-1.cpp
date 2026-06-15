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
    void dfs(TreeNode* root, int value, int& counter){
        if(root==nullptr) return;
        
        TreeNode* leftnode = root->left;
        TreeNode* rightnode = root->right;
        if(leftnode){
            if(leftnode->val >= value){
                counter++;
                dfs(root->left, leftnode->val, counter);
            }
            else{
                dfs(root->left, value, counter);
            }

        }
        if(rightnode){
            if(rightnode->val >= value){

                counter++;
                dfs(root->right, rightnode->val, counter);
            }
            else{
                dfs(root->right, value, counter);
            }

        }
    }
    int goodNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        int counter = 1;
        dfs(root, root->val, counter);
        return counter;    
    }
};
