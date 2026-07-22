class Solution {
public:
    int dpsolution(int l, int r, vector<vector<int>>& dp, vector<int>& newnums){
        if(l > r){
            return 0;
        }

        if(dp[l][r]!=-1){
            return dp[l][r];
        }

        dp[l][r] = 0;

        for(int i=l; i<=r; i++){
            int coins = newnums[l-1]*newnums[i]*newnums[r+1];
            coins += dpsolution(l, i-1, dp, newnums) + dpsolution(i+1, r, dp, newnums);
            dp[l][r] = max(dp[l][r], coins);
        }
        return dp[l][r];        
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> newnums(nums.size() + 2, -1);
        newnums[0] = 1;
        newnums[newnums.size()-1] = 1;
        vector<vector<int>> dp(n+2, vector<int>(n+2, -1));
        
        newnums[0] = 1;
        newnums[newnums.size()-1] = 1;

        for(int i=0; i<n; i++){
            newnums[i+1] = nums[i];
        }

        dpsolution(1, n, dp, newnums);
        return dp[1][n];
    }
};
