class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> st;
        int n = s.size();
        int left = 0;
        int maxlen = 0;

        for(int right=0; right<n; right++){
            while(st.find(s[right])!=st.end()){
                st.erase(s[left]);
                left++;
            }
            st.insert(s[right]);
            maxlen = max(maxlen, right-left+1);
        }

        return maxlen;
    }
};
