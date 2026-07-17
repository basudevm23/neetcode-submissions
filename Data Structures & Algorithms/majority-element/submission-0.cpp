class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // for solving this problem in linear time, which means no data structure
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n/2];
    }
};