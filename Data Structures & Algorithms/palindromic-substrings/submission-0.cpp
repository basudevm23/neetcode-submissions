class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        
        int res = 0;

        for(int i=0; i<n; i++){
            int l = i;
            int r = i;
            while(l>=0 && r<n && s[l]==s[r]){
                res++;
                r++;
                l--;
            }
        // here checking for even sized palindromes
            int lnew = i;
            int rnew = i+1;
            while(lnew>=0 && rnew<n && s[lnew]==s[rnew]){
                res++;
                rnew++;
                lnew--;
            }
           
        }
   
        return res; 
    }
};
