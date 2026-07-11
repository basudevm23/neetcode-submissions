class Solution {
public:
    int dpsolution(string s, vector<int>& dp, int index){

        if(index>=s.size()) return 1;
        if(s[index]=='0') return 0;
        
        if(dp[index]!=-1){
            return dp[index];
        }
        
        dp[index] = dpsolution(s, dp, index+1);
        if(index+1<s.size() && (s[index]=='1' || (s[index] == '2' && s[index+1] <= '6'))){
            dp[index]+= dpsolution(s, dp, index+2);
        }
        return dp[index];
    }
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n+1, -1);
        return dpsolution(s, dp, 0);    
    }
};
