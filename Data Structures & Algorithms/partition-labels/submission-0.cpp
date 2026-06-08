class Solution {
public:
    bool check(vector<int>& hashcount, vector<int>& hashcountnew){
        for(int i=0; i<hashcount.size(); i++){
            if(hashcountnew[i]!=0 && hashcountnew[i]!=hashcount[i]){
                return false;
            }
            
        }
        return true;
    }
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> hashcount(26, 0);
        for(int i=0; i<n; i++){
            hashcount[s[i]-'a']++;
        }
        int l =0;
        int r = 0;
        vector<int> ans;
        vector<int> hashcountnew(26, 0);
        while(r<n){
            
            hashcountnew[s[r]-'a']++;
            if(check(hashcount, hashcountnew)){
                ans.push_back(r-l+1);
                hashcount[s[r]-'a']--;
                l=r+1;
                r++;
                fill(hashcountnew.begin(), hashcountnew.end(), 0);
            }
            else{
                r++;
            }

        }
        return ans;
    }
};
