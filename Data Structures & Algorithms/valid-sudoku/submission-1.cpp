class Solution {
   public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            vector<char> row = board[i];
            unordered_set<char> seen;
            for (char ch : row) {
                if (ch != '.') {
                    if (!seen.insert(ch).second) {
                        return false;
                    }
                }
            }
        }

        for (int i = 0; i < 9; i++) {
            unordered_set<char> seen;
            for (int j = 0; j < 9; j++) {
                if (board[j][i] != '.') {
                    if (!seen.insert(board[j][i]).second) {
                        return false;
                    }
                }
            }
        }

        for (int square = 0; square < 9; square++) {
            unordered_set<char> seen;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int row = (square / 3) * 3 + i;
                    int col = (square % 3) * 3 + j;
                    if (board[row][col] != '.') {
                        if (!seen.insert(board[row][col]).second) {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};