class Solution {
public: 
    int dpsolution(int i, int j, vector<vector<int>>& dp, string s1, string s2, string s3){
        if(i==s1.length() and j == s2.length()){
            return 1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(i < s1.length() && s1[i] == s3[i+j] && dpsolution(i+1, j, dp, s1, s2, s3)){
            dp[i][j]=1;
            return 1;
        }

        if(j<s2.length() && s2[j] == s3[i+j] && dpsolution(i, j+1, dp, s1, s2, s3)){
            dp[i][j]=1;
            return 1;
        }
        dp[i][j] = 0;
        return dp[i][j];
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length() == 0 && s2.length()==0 && s3.length()==0){
            return true;
        }
        if(s1.length() + s2.length() != s3.length()){
            return false;
        }
        // i for s1 and j for s2
        vector<vector<int>> dp(s1.length()+1, vector<int>(s2.length()+1, -1));

        dpsolution(0, 0, dp, s1, s2, s3);

        return dp[0][0];        
    }
};
