class Solution {
public:
    void solve(vector<vector<char>>& board) {
        queue<pair<int, int>> q;
        int ROWS = board.size();
        int COLS = board[0].size();

        vector<vector<int>> vis(ROWS, vector<int>(COLS, 0));

        for(int r = 0; r<ROWS; r++){
            for(int c =0; c<COLS; c++){
                if((r ==0 || r==ROWS-1 || c==0 || c==COLS-1)&& board[r][c]=='O'){
                    q.push({r, c});
                    vis[r][c]=1;
                }
            }
        }
        
        vector<pair<int, int>> direct = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        while(!q.empty()){
            int n =q.size();
            for(int i=0; i<n; i++){
                pair<int,int> node = q.front();
                q.pop();
                for(pair<int, int> p: direct){
                    int roww = p.first;
                    int coll = p.second;

                    int r = roww + node.first;
                    int c =coll + node.second;

                    if(r<0 || c<0 || r>=ROWS || c>=COLS || board[r][c]=='X' || vis[r][c]==1){
                        continue;                       
                    }
                    vis[r][c] =1;
                    q.push({r, c});
                }

            }    
        } 
        for(int r=0; r<ROWS; r++){
            for(int c=0; c<COLS; c++){
                if(vis[r][c]!=1 && board[r][c]=='O'){
                    board[r][c]='X';
                }
            }
        }   
    }
};









































