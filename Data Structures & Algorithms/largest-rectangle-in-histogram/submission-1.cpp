class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        // index, height in the pair
        int n = heights.size();
        if(n==0){
            return 0;
        }
        if(n==1){
            return heights[0];
        }
        int maxarea = heights[0];
        for(int i=0; i<n; i++){
            if(st.empty()){
                st.push({i, heights[i]});
                continue;
            }
            int indexxt = st.top().first;
            int heightt = st.top().second;
            if(heights[i]>heightt){
                st.push({i, heights[i]});
            }   
            else{
                int starti = i;
                while(!st.empty()&&st.top().second>heights[i]){
                    maxarea = max(maxarea, st.top().second*(i-st.top().first));
                    starti = st.top().first;
                    st.pop();

                }
                st.push({starti, heights[i]});
            }         
        }
        if(st.empty()){
            return maxarea;
        }
        while(!st.empty()){
            maxarea = max(maxarea, st.top().second*(n-st.top().first));
            st.pop();
        }
        return maxarea;
    
    }
};
