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
    int ans;
    void dfstraversal(TreeNode* root, int& k, int target){
        if(root==nullptr) return;
        
        dfstraversal(root->left, k, target);
        k++; 
        if(k==target){
            ans = root->val;
            return;
        }       
        dfstraversal(root->right, k, target);
    }
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0;
        dfstraversal(root, counter, k);
        return ans;
    }
};
