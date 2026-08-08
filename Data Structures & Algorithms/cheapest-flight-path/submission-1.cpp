class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        queue<pair<pair<int, int>, int>> q;
        
        vector<vector<pair<int, int>>> adj(n);

        for(auto flight: flights){
            int from = flight[0];
            int to = flight[1];
            int price = flight[2];

            adj[from].push_back({to, price});
        } 

        q.push({{src, 0}, 0});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while(!q.empty()){
            auto it = q.front();
            q.pop();

            int node = it.first.first;
            int dis = it.first.second;
            int stops = it.second;

            if(stops > k) continue;

            for(auto x: adj[node]){
                int adjnode = x.first;
                int wt = x.second;

                if(wt + dis < dist[adjnode]){
                    dist[adjnode] = wt + dis;
                    q.push({{adjnode, dist[adjnode]}, stops + 1});
                }
            }
        }

        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];
    }
};
