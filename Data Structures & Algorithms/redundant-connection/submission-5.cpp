class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        // a tree cannot contain a cycle, while adding edges one by one, the first edge
        // that creates a cycle is the redundant connection

        vector<vector<int>> adj(edges.size()+1);
        
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            vector<bool> vis(edges.size()+1, false);

            if(dfs(u, -1, vis, adj)){
                return {u, v};
            }
        }
        
    }

    bool dfs(int node, int parent, vector<bool>& vis, vector<vector<int>>& adj){
        vis[node] = true;
        for(auto nei: adj[node]){
            if(nei == parent) continue;
            if(vis[nei]) return true;
            if(dfs(nei, node, vis, adj)) return true;
        }
        return false;
    }
};
