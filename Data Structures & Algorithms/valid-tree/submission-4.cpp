class Solution {
    int flag  =0;
public:
    bool dfs(int node, int parent , unordered_set<int>& visit, vector<vector<int>>& adj){

        if(visit.count(node)) return false;

        visit.insert(node);

        for(int neighbor: adj[node]){
            if(neighbor == parent){
                continue;
            }
            if(!dfs(neighbor, node, visit, adj)) return false;
        } 
        return true;     
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()>n-1) return false;
        vector<vector<int>> adj(n);
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        unordered_set<int> visit;
        if(!dfs(0, -1, visit, adj)) return false;
        return visit.size()==n;
    }
};
