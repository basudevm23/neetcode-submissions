class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // non overlapping intervals
        vector<vector<int>> ans;
        
        int n =intervals.size();

        sort(intervals.begin(), intervals.end());
        ans.push_back(intervals[0]);

        for(int i=1; i<n;i++){
            int lastend = ans[ans.size()-1][1];
            if(intervals[i][0]<=lastend){
                ans[ans.size()-1][1] = max(lastend, intervals[i][1]);
            }
            else{
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }
};
