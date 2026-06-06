class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> setr[9];
        unordered_set<char> setc[9];
        unordered_set<char> setsq[9];
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                char num = board[i][j];
                if(num == '.'){
                    continue;
                }
                char box = (j/3)*3 + (i/3);
                if(setr[i].count(num)||setc[j].count(num)||setsq[box].count(num)){
                    return false;
                }
                setr[i].insert(num);
                setc[j].insert(num);
                setsq[box].insert(num)   ;            
            }
        }
        return true;
    }
};
