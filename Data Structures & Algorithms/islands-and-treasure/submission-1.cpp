class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(ROWS, vector<int>(COLS,0));
        for(int r = 0; r< ROWS; r++){
            for(int c =0; c<COLS; c++){
                vis[r][c] = 0;
            }
        }
        for(int r=0; r<ROWS; r++){
            for(int c=0; c<COLS; c++){
                if(grid[r][c]==0){
                    q.push({r, c});
                    vis[r][c]=1;
                }
            }
        }
        int distance = 0;
        
        vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0 , -1}};
        while(!q.empty()){
            int n = q.size();
            for(int i=0; i<n ; i++){
                pair<int, int> p = q.front();
                int r= p.first;
                int c = p.second;
                q.pop();
                grid[r][c] = distance;
                for(int j=0; j<directions.size(); j++){
                    int dr = directions[j].first;
                    int dc = directions[j].second;

                    int row = dr + r;
                    int col = dc + c;

                    if(row<0 || col <0 || row>=ROWS || col >=  COLS || grid[row][col]==-1 || vis[row][col]==1){
                        continue;
                    }
                    q.push({row, col});
                    vis[row][col] = 1;
                }
                
            }
            distance++;
        }
    }
};
