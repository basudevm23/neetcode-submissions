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
    void dfstraversal(TreeNode* root, priority_queue<int, vector<int>, greater<int>>& pq){
        if(root==nullptr) return;
        pq.push(root->val);
        dfstraversal(root->left, pq);
        dfstraversal(root->right, pq);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(root==nullptr) return 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        int ans = -1;
        dfstraversal(root, pq);
        while(k){
            ans = pq.top();
            pq.pop();
            k--;
        }
        return ans;
    }
};
