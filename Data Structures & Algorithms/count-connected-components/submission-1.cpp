class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<int>& vis, int node){
        vis[node] = 1;
        for(int i=0; i<adj[node].size(); i++){
            // visited array equals to -1 means not visited
            if(vis[adj[node][i]]==-1){
                dfs(adj, vis, adj[node][i]);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, -1);
        int res = 0;

        for(int i=0; i<vis.size(); i++){
            // visited array equals to -1 means not visited
            if(vis[i]==-1){
                res++;
                dfs(adj, vis, i);
            }
        }
        return res;
    }
};
