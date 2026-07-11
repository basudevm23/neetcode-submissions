class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int res = nums[0];
        int currMax = 1;
        int currMin = 1;

        for(auto num: nums){
            int tmpmax = currMax*num;
            int tmpmin = currMin*num;
            currMax = max(max(tmpmax, tmpmin), num);
            currMin = min(min(tmpmax, tmpmin), num);
            res = max(res, currMax);
        }
        return res;
    }
};
