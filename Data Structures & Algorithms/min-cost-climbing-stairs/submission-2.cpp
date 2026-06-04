class Solution {
public:
    int minvalue(vector<int>& cost, vector<int>& dp, int i){
        if(i<=1){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int left = minvalue(cost,dp, i-1)+ (cost[i-1]);
        int right = minvalue(cost, dp, i-2) + (cost[i-2]);

        return dp[i] = min(left, right);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n =cost.size();
        vector<int> dp(n+1, -1);
        return minvalue(cost, dp, n);
        // cost, dp(4, -1), 2
    }
};
