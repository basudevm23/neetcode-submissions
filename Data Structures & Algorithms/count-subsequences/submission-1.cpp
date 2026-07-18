class Solution {
public:
    int dpsolution(string s, string t, int l, int r, vector<vector<int>>& dp){
        if(r==t.size()) return 1;
        if(l == s.size()) return 0;
        // l pointer is on the s string and the r pointer is on the t string
        if(dp[l][r]!= -1) return dp[l][r];

        if(s[l]==t[r]){
            dp[l][r] = dpsolution(s, t, l+1, r+1, dp) + dpsolution(s, t, l+1, r, dp);
        }

        else dp[l][r] = dpsolution(s, t, l+1, r, dp);   
        return dp[l][r];    
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
        int l = 0;
        int r = 0;        
        return dpsolution(s, t, l, r, dp);
    }
};
