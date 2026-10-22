class Solution {
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int check(int r, int c, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;
// the for loop would run 4 times
        for(auto dir: directions){
            int rnew = r + dir.first;
            int cnew = c + dir.second;

            if(rnew < 0 || cnew < 0 || rnew > m-1 || cnew > n-1 || grid[rnew][cnew] == 0){
                continue;
            }
            cnt++;
        }

        return 4 - cnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // we are pretty sure that all the land pieces are connected to each other
        // one means land, zero means water
        int count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j <n; j++){
                if(grid[i][j] == 1){
                    count = count + check(i, j, grid);
                }
            }
        }

        return count;
    }
};