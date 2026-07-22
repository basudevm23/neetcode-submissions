class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length()+1, vector<int>(word2.length()+1, 0));
        
        for(int r = 0; r< word1.length()+1; r++){
            dp[r][word2.length()] = word1.length() - r;
        }

        for(int c = 0; c < word2.length()+1; c++){
            dp[word1.length()][c] = word2.length() - c;
        }
        for(int i = word1.length()-1; i>=0; i--){
            for(int j = word2.length()-1; j>=0; j--){
                if(word1[i] == word2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i+1][j], min(dp[i][j+1], dp[i+1][j+1]));
                }
            }
        }
        return dp[0][0];
    }
};
