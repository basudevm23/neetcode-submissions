class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n =points.size();
        for(int i=0; i<n; i++){
            int distance = pow(points[i][0] , 2) + pow(points[i][1], 2);
            pq.push({distance, {points[i][0], points[i][1]}});
        }
        vector<vector<int>> ans;
        while(k){
            vector<int> res;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            res.push_back(x);
            res.push_back(y);
            ans.push_back(res);
            k--;
        } 
        return ans;           
    }
};
