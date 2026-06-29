class Solution {
public:
    bool backtracking(vector<vector<char>>& board, int r, int c, int i, string word, set<pair<int, int>>& st){
        if(i==word.size()) return true;
        if(r<0 || c<0 || r>=board.size() || c>=board[0].size() || st.find({r, c})!=st.end() || board[r][c]!=word[i]){
          return false;
        }
        st.insert({r, c});
        bool res = backtracking(board, r+1, c, i+1, word, st) || backtracking(board, r-1, c, i+1, word, st) || backtracking(board, r, c+1, i+1, word, st) || backtracking(board, r, c-1, i+1, word, st);
        st.erase({r, c});
        return res;   
    }
    bool exist(vector<vector<char>>& board, string word) {
        // bunch of characters are given in it
        // the word could be constructed horizontally or vertically
        // backtracking recursively
        int m =board.size();
        int n=board[0].size();
        set<pair<int, int>> st;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(backtracking(board,i, j, 0, word, st)==true){
                    return true;
                }                
            }
        }
        return false;
    }
};
