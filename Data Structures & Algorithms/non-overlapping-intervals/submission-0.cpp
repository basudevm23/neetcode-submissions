class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // we want to remove that interval which ends late
        // we sort the array based on the starting value

        int n = intervals.size();
        sort(intervals.begin(), intervals.end());
        int prevend = intervals[0][1];
        int res = 0;
        for(int i=1; i<n; i++){
            if(intervals[i][0] >= prevend){
                prevend = intervals[i][1];
            }
            else{
                prevend = min(intervals[i][1], prevend);
                res++;
            }
        }
        return res;

    }
};
