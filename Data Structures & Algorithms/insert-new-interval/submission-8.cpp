class Solution {
    // remember the insert syntax well and the condition for non overlapping
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        
        if(intervals.empty()){

           intervals.push_back(newInterval);
           return intervals;
        }    
        int n = intervals.size();   
        int minindex = INT_MAX;
        int maxindex = -1;
        if(newInterval[0]>intervals[n-1][1]){
            intervals.push_back(newInterval);
            return intervals;
        }
        if(newInterval[1]<intervals[0][0]){
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        for(int i=0; i<n;i++){
            if(i<n-1 && intervals[i][1] < newInterval[0] && intervals[i+1][0]>newInterval[1]){
                intervals.insert(intervals.begin()+i+1, newInterval);
                return intervals;
            }
            if((intervals[i][1] >= newInterval[0] && intervals[i][0] <= newInterval[1])){
                minindex= min(minindex, i);
                maxindex = max(maxindex, i);
            }
        }
        if(maxindex==-1) return intervals;
        int a = min(intervals[minindex][0], newInterval[0]);
        int b = max(intervals[maxindex][1], newInterval[1]);
        
        intervals.erase(intervals.begin()+ minindex, intervals.begin()+ maxindex+1);
        intervals.insert(intervals.begin() + minindex, {a, b});

        return intervals;
      
    }
};
