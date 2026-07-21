class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // decreasing priority queue so that the min distance is placed at the top

        vector<vector<pair<int, int>>> adj(n+1);

        for(int i = 0; i< times.size(); i++){
            int ui = times[i][0];
            int vi = times[i][1];
            int ti = times[i][2];

            adj[ui].push_back({vi, ti});
        }

        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it: adj[node]){
                int neighbornode = it.first;
                int timetaken = it.second;
                
                if(distance + timetaken < dist[neighbornode]){
                    dist[neighbornode] = distance + timetaken;
                    pq.push({dist[neighbornode], neighbornode});
                }
            }
            
        }
        dist[0] = INT_MIN;
        int res = *max_element(dist.begin(), dist.end());
        if(res == INT_MAX){
            return -1;
        }
        return res;
    }
};
