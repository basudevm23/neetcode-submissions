class Solution {
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int r = 0; r<m; r++){
            for(int c = 0; c < n; c++){
                if(grid[r][c] == 0){
                    q.push({r, c});
                    vis[r][c]=1;
                }
            }
        }
        int dist = 1;
        while(!q.empty()){
            int qsize = q.size();
            for(int i = 0; i < qsize; i++){
                int r = q.front().first;
                int c = q.front().second;

                q.pop();

                for(auto dir: directions){
                    int rnew = r + dir.first;
                    int cnew = c + dir.second;

                    if(rnew < 0 || cnew < 0 || rnew > m-1 || cnew > n-1 || grid[rnew][cnew] == -1 || vis[rnew][cnew] == 1){
                        continue;
                    }
                    grid[rnew][cnew] = dist;
                    q.push({rnew, cnew});
                    vis[rnew][cnew] = 1;
                }
            }
            dist++;
        }
    }
};
