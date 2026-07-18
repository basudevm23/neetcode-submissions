class Solution {
public:
    int dpsolution(vector<int>& prices, int index, int flag_buy, vector<vector<int>>& dp){
        if(index>=prices.size()){
            return 0;
        }
        if(dp[index][flag_buy]!=-1){
            return dp[index][flag_buy];
        }

        int skip = dpsolution(prices, index + 1, flag_buy, dp);
        int sell = INT_MIN;
        int buy = INT_MIN;
        if(flag_buy){
            sell = prices[index] + dpsolution(prices, index + 2 , 0, dp);

        }
        else if(flag_buy == 0){
            buy = dpsolution(prices, index + 1, 1, dp) - prices[index];
        }
        return dp[index][flag_buy] = max(max(skip, buy), sell);
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return dpsolution(prices, 0, 0,dp);
    }
};
