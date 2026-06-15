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
    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> res;
        if(root==nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> final;
            int  n =q.size();
            for(int i=0; i<n; i++){
                TreeNode* temp = q.front();
                final.push_back(temp->val);
                q.pop();
                if(temp->left != nullptr) q.push(temp->left);
                if(temp->right != nullptr) q.push(temp->right);
            }
            ans.push_back(final);
        }
        int k =ans.size();
        for(int i=0; i<k;i++){
            res.push_back(ans[i][ans[i].size()-1]);
        }
        return res;
    }
};
