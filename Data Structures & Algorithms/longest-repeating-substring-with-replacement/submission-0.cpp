class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> counthash(26, 0);
        int l =0;
        int ans =0;

        for(int r =0; r<s.size(); r++){
            counthash[s[r]-'A']++;
            int maxx = *max_element(counthash.begin(), counthash.end());

            while((r-l+1) - maxx > k){
                counthash[s[l]-'A']--;
                l++;
            }
            ans= max(ans, r-l+1);
        }
        return ans;
    }
};
