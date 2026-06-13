class Solution {
public:
    string minWindow(string s, string t) {
        // we have to keep two hasharrays
        // also for haves and needs;
        if(s.size()<t.size()) return "";
        if(s == t) return s;
        int l=0;
        int r = 0;
        int minstr=INT_MAX;
        int leftindex= 0 ;
        int rightindex = 0;
        int have = 0;
        int need=  0;
        unordered_map<char, int> hashs;
        unordered_map<char, int> hasht;

        for(int i=0; i<t.size(); i++){
            if(hasht[t[i]]==0){
                need++;
            }
            hasht[t[i]]++;
        }

        while(l<=r&&r<s.size()){
            if(hasht.find(s[r])!=hasht.end()){
                hashs[s[r]]++;
                if(hashs[s[r]]==hasht[s[r]]){
                    have++;
                }
            }
            while(have==need && l<=r){
                if(r-l+1 <minstr){
                    minstr = r-l+1;
                    rightindex = r;
                    leftindex = l;
                }
                if(hasht.find(s[l])!=hasht.end() && hashs[s[l]]==hasht[s[l]]){
                    have--;
                }
                if(hashs.find(s[l])!=hashs.end()){
                    hashs[s[l]]--;
                }            
                
                l++;
            }
            r++;                    
        }
        if(minstr ==INT_MAX){
            return "";
        }
        return s.substr(leftindex, minstr);
    }
};
