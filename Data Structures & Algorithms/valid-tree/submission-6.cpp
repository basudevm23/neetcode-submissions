class Solution {
    int cnt = 0;
public:
    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        cnt++;
        for(int adjnode: adj[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode, node, vis, adj)){
                    return true;
                }
            }
            else if(adjnode != parent){
                return true;
            }
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        vector<int> vis(n, 0);

        for(auto edge: edges){
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        bool res = !dfs(0, -1, vis, adj);
        if(cnt != n){
            return false;
        }

        return res;
    }
};
