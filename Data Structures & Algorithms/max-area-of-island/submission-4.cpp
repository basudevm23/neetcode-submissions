class Solution {
public:
    void bfs(vector<vector<int>>& adj, vector<int>& vis, queue<int>& q, int &count){
        while(!q.empty()){

            int node = q.front();
            q.pop();
            count++;
            for(int i=0; i<adj[node].size(); i++){
                if(!vis[adj[node][i]]){
                    q.push(adj[node][i]);
                    vis[adj[node][i]] =1;
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> adj(m*n);
        vector<int> vis(m*n, 0);
        queue<int> q;

        for(int r=0; r<grid.size(); r++){
            for(int c=0; c<grid[0].size(); c++){
                if(grid[r][c]==1){
                    if(r+1<m){
                        if(grid[r+1][c]==1){
                            adj[r*n + c].push_back((r+1)*n + c);;
                        }
                    }
                    if(r-1>=0){
                        if(grid[r-1][c]==1){
                            adj[r*n + c].push_back((r-1)*n + c);;
                        }
                    }

                    if(c+1<n){
                        if(grid[r][c+1]==1){
                            adj[r*n + c].push_back(r*n + c+1);;
                        }
                    }

                    if(c-1>=0){
                        if(grid[r][c-1]==1){
                            adj[r*n + c].push_back(r*n + c-1);;
                        }
                    }                    
                }
            }
        }
        int maxarea = 0;
        for(int i=0; i<vis.size(); i++){

            int r = i/n;
            int c = i%n;
            if(grid[r][c] == 1 && !vis[i]){
                int count = 0;
                q.push(i);
                vis[i] = 1;
                
                bfs(adj, vis, q, count);
                maxarea = max(count, maxarea);
            
            }
        }
        return maxarea;
    }
};
