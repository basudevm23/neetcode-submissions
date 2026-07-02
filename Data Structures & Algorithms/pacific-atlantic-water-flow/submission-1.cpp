class Solution {
public:
    void dfs(int r, int c, vector<vector<int>>& vis, int prevHeight, vector<vector<int>>& heights){
        int ROWS = heights.size();
        int COLS = heights[0].size();
        if(r<0 || c<0 || r>=ROWS || c>= COLS || vis[r][c]==1 || heights[r][c]< prevHeight){
            return;
        }
        vis[r][c] = 1;
        dfs(r+1, c, vis, heights[r][c], heights);
        dfs(r-1, c, vis, heights[r][c], heights);
        dfs(r, c+1, vis, heights[r][c], heights);
        dfs(r, c-1, vis, heights[r][c], heights);       
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int ROWS = heights.size();
        int COLS = heights[0].size();
        vector<vector<int>> vispacific(ROWS, vector<int>(COLS, 0));
        vector<vector<int>> visatlantic(ROWS, vector<int>(COLS, 0));
        
        for(int c=0; c<COLS; c++){
            dfs(0, c, vispacific, heights[0][c], heights);
            dfs(ROWS-1, c, visatlantic, heights[ROWS-1][c], heights);
        }  

        for(int r =0; r<ROWS; r++){
            dfs(r, 0, vispacific, heights[r][0], heights);
            dfs(r, COLS-1, visatlantic, heights[r][COLS-1], heights);
        } 
        vector<vector<int>> res;
        for(int r=0; r<ROWS; r++){
            for(int c=0; c< COLS; c++){
                if(visatlantic[r][c]==1 && vispacific[r][c]==1){
                    res.push_back({r,c});
                }
            }
        }
        return res;
    }
};
