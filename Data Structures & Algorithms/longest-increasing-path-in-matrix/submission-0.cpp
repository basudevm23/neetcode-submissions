class Solution {
public:
    int dpsolution(int r, int c, int prevValue, vector<vector<int>>& matrix, vector<vector<int>>& dp){
        if(r<0 || r>=matrix.size() || c < 0 || c>=matrix[0].size() || matrix[r][c]<= prevValue){
            return 0; 
        }
        if(dp[r][c]!= -1){
            return dp[r][c];
        }
        int res = 0;

        res = max(res, 1 + dpsolution(r+1,c, matrix[r][c], matrix, dp));
        res = max(res, 1 + dpsolution(r,c+1, matrix[r][c], matrix, dp));
        res = max(res, 1 + dpsolution(r,c-1, matrix[r][c], matrix, dp));
        res = max(res, 1 + dpsolution(r-1,c, matrix[r][c], matrix, dp));

        dp[r][c] = res;
        return dp[r][c];        
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
        int maxi = -1;
        for(int r = 0; r<matrix.size(); r++){
            for(int c =0 ; c<matrix[0].size(); c++){
                maxi = max(maxi, dpsolution(r, c, -1, matrix, dp));
            }
        }
        return maxi;                
    }
};
