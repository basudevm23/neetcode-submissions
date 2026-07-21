class Solution {
public:
    unordered_set<int> cols;
    unordered_set<int> posdiag;
    unordered_set<int> negdiag;
    vector<vector<string>> res;


    void backtrack(int r, int n, vector<string>&  board){
        if(r==n){
            res.push_back(board);
            return;
        }
        for(int c=0; c<n; c++){
            if(cols.count(c)|| posdiag.count(r+c)|| negdiag.count(r-c)){
                continue;
            }
            cols.insert(c);
            posdiag.insert(r+c);
            negdiag.insert(r-c);
            board[r][c] = 'Q';

            backtrack(r+1, n , board);

            cols.erase(c);
            posdiag.erase(r+c);
            negdiag.erase(r-c);
            board[r][c] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(0, n, board);
        return res;
    }
};
