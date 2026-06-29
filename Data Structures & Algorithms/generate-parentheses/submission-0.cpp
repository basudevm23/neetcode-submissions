class Solution {
public:
    void addparen(int open, int close, vector<string>& res, string ans, int n){
        if(close==n && open==n){
            res.push_back(ans);
            return;
        }   
        if(open==close){
            ans.push_back('(');
            addparen(open+1, close, res, ans, n); 
            ans.pop_back();       
        } 
        if(open>close){
            if(open<n){
                ans.push_back('(');
                addparen(open+1, close, res, ans, n);
                ans.pop_back();
            }
            ans.push_back(')');
            addparen(open, close + 1, res, ans, n);
            ans.pop_back();  
            // include a pop_back here as well
        }
    }
    vector<string> generateParenthesis(int n) {
        // start thinking from brute force
        // n  =3, 3 open and 3 closed 

        // we can start with only opening parathensis 

        // we can add a closing parenthesis only if the open < close
        int open = 0;
        int close = 0;
        vector<string> res;
        string ans;
        addparen(open, close, res, ans, n);

        return res;
    }
};
