class Solution {
    vector<vector<string>> res;
public:
    bool checkpalindrome(string &s, int l, int r){
        while(l<r){
            if(s[l]!=s[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
        
    }
    void dfs(int l, int r, string &s, vector<string> &part){
        if(r>=s.size()){
            if(l==r) res.push_back(part);

            return;
        }
        if(checkpalindrome(s, l, r)){
            part.push_back(s.substr(l, r-l+1));
            dfs(r+1, r+1, s, part);
            part.pop_back();

        }
        dfs(l, r+1, s, part);

    }
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(0, 0, s, part);
        return res;        
    }
};
