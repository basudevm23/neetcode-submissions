class Solution {
public:
    bool dpmemoization(vector<int>& nums, int index, int target, vector<vector<int>>& dparray){
        if(index==nums.size()){
            return target == 0;
        }
        if(target<0) return false;
        if(dparray[index][target]!=-1){
            return dparray[index][target];
        }
        return dparray[index][target] = dpmemoization(nums, index + 1, target, dparray) ||
                                        dpmemoization(nums, index+1, target - nums[index], dparray);
    }

    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        for(int i=0; i<nums.size(); i++){
            total_sum = total_sum + nums[i];
        }

        // if the total_sum is odd then return false

        if(total_sum%2 != 0 ) return false;

        vector<vector<int>> dparray(nums.size(), vector<int>(total_sum/2 + 1, -1));

        return dpmemoization(nums, 0, total_sum/2, dparray);
    }
};
