class Solution {
public:
    int dpsolution(vector<int>& nums,int index, int target){
        if(index == nums.size()){
            return target == 0;
        }

        int addelement = dpsolution(nums, index + 1, target - nums[index]);
        int subtractelement = dpsolution(nums, index + 1, target + nums[index]);

        return addelement + subtractelement;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return dpsolution(nums, 0, target);
    }
};
