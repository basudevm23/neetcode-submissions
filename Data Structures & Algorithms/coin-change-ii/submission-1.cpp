class Solution {
public:
    int dfssolution(int index, int curramt, vector<int>& coins, int target, vector<vector<int>>& dp){
        if(curramt == target){
            return 1;
        } 
        if(curramt > target){
            return 0;
        }
        if(index==coins.size()){
            return 0;
        }   
        if(dp[index][curramt]!= -1){
            return dp[index][curramt];
        }
        dp[index][curramt] = dfssolution(index + 1, curramt, coins, target, dp) + dfssolution(index, curramt + coins[index], coins, target, dp);
        return dp[index][curramt];
    }
    int change(int amount, vector<int>& coins) {
        // the rows would be the coins and the columns would be the amount that we are chasing 
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        dfssolution(0, 0, coins, amount, dp);
        if(dp[0][0]==-1){
            return 1;
        }
        return dp[0][0];
    }
};
