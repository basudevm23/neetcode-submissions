class Solution {
public:
    int dpresult(int index, int end, vector<int>& nums, vector<int>& dp) {
        if (index > end)
            return 0;

        if (dp[index] != -1)
            return dp[index];

        int robCurrent = nums[index] + dpresult(index + 2, end, nums, dp);
        int skipCurrent = dpresult(index + 1, end, nums, dp);

        return dp[index] = max(robCurrent, skipCurrent);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        // Case 1: Rob from house 0 to n-2
        int case1 = dpresult(0, n - 2, nums, dp1);

        // Case 2: Rob from house 1 to n-1
        int case2 = dpresult(1, n - 1, nums, dp2);

        return max(case1, case2);
    }
};