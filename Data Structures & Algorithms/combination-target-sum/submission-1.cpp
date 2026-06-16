class Solution {
public:
    void dfs(vector<int>& nums,vector<int>& curr, int total, int index, int target, vector<vector<int>>& res){
        // if the target is met then immediately return
        if(total == target){
            res.push_back(curr);
            return;
        }
        // if it is going out of ranges
        if(index>=nums.size() || total>target){
            return;
        }
        curr.push_back(nums[index]);
        dfs(nums, curr, total + nums[index], index,target, res);
        curr.pop_back();
        dfs(nums, curr, total, index+1,target, res);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> curr;

        dfs(nums, curr, 0, 0, target, res);
        return res;               
    }
};
