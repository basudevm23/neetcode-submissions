class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;

        for(auto num: nums){
            st.insert(num);
        }
        int maxlen = 0;
        for(auto num: st){
            if(st.find(num-1)==st.end()){
                int currlen = 1;
                while(st.find(num+currlen)!=st.end()){
                    currlen++;
                }
                maxlen = max(maxlen, currlen);
            }
        }
        return maxlen;
    }    
};