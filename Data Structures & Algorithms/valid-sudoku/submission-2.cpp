class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> row(9);
        vector<int> col(9);
        vector<int> square(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0';
                    int mask = 1 << num;
                    if(row[i] & mask) {
                        return false;
                    }
                    if (col[j] & mask) {
                        return false;
                    }
                    int sq = (i/3)*3 + (j/3);
                    if (square[sq] & mask) {
                        return false;
                    }
                    row[i] |= mask;
                    col[j] |= mask;
                    square[sq] |= mask;
                }
            }
        }
        return true;
    }
};
