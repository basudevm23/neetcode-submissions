class Solution {
    // 1, 1, 2  1,2,3
public:
    void backtrack(vector<int>& nums, int index, vector<int>& res, vector<vector<int>>& ans){
        int n = nums.size();
        if(index>=n){
            ans.push_back(res);
            return;
        }
        res.push_back(nums[index]);
        backtrack(nums, index+1, res, ans);
        res.pop_back();
        backtrack(nums, index+1, res, ans);        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int n =nums.size();
        vector<int> res;
        vector<vector<int>> ans;

        backtrack(nums, 0, res, ans);
        return ans;
    }
};
