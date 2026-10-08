class Solution {
public:
    void dfs(int i, vector<int>& vis, vector<vector<int>>& adj){
        vis[i] = 1;

        for(int adjnode: adj[i]){
            if(!vis[adjnode]){
                dfs(adjnode, vis, adj);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto edge: edges){
            int a = edge[0];
            int b = edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<int> vis(n, 0);
        int cnt = 0;
        for(int i = 0; i <n; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                cnt++;
            }
        }
        return cnt;
    }
};
