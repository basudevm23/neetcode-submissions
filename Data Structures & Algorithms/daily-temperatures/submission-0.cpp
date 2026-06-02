class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int, int>> st;
        int n = temperatures.size();
        vector<int> ans(n, 0);

        for(int i=0; i<n;i++){
            while(!st.empty()&& temperatures[i]>st.top().first){
                int temp = st.top().first;
                int index = st.top().second;
                st.pop();
                ans[index] = i-index;
            }
            st.push({temperatures[i], i});
        }
        return ans;
    }
};
