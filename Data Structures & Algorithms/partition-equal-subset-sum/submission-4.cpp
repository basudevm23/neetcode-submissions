class Solution {
public:
    bool dpsol(vector<int>& nums, int index, int target, vector<vector<int>>& dp){
        if(index == nums.size()-1){
            return target == 0;
        }

        if(target < 0){
            return false;
        }

        if(dp[index][target]!=-1){
            return dp[index][target];
        }

        bool takeitone = dpsol(nums, index+1, target, dp);
        bool takeittwo = dpsol(nums, index+1, target - nums[index], dp);

        return dp[index][target] = takeitone || takeittwo;
    }

    bool canPartition(vector<int>& nums) {
        int total_sum = 0;

        for(int i=0; i<nums.size(); i++){
            total_sum = total_sum + nums[i];
        }

        if(total_sum%2 != 0){
            return false;
        }   

        vector<vector<int>> dp(nums.size(), vector<int>(total_sum/2 + 1, -1));

        return dpsol(nums, 0, total_sum/2, dp);    
    }
};
