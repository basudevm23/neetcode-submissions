class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[n-1] = 1;
        int result = 1;
        for(int i=n-2; i>=0; i--){
            int currlength = 1;
            for(int j=i+1; j<n; j++){
                if(nums[j]>nums[i]){
                   currlength = max(currlength, 1 + dp[j]);
                }
            }
            dp[i] = currlength;
            result = max(result, dp[i]);
        }
        return result;
    }
};
