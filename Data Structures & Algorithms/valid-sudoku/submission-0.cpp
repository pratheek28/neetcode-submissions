class Solution {
    bool validRow(int i, const vector<vector<char>>& board) {
        unordered_map<char, int> hashMap;

        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;

            if (hashMap.find(board[i][j]) != hashMap.end()) {
                return false;
            }
            hashMap[board[i][j]]++;
        }

        return true;
    }

    bool validCol(int j, const vector<vector<char>>& board) {
        unordered_map<char, int> hashMap;

        for (int i = 0; i < 9; i++) {
            if (board[i][j] == '.') continue;

            if (hashMap.find(board[i][j]) != hashMap.end()) {
                return false;
            }
            hashMap[board[i][j]]++;
        }

        return true;
    }

    bool check3x3(int i, int j, const vector<vector<char>>& board) {

        unordered_map<char, int> hashMap;

        for (int col = i; col < i + 3; col++) {
            for (int row = j; row < j + 3; row++) {
                if (board[col][row] == '.') continue;
                if (hashMap.find(board[col][row]) != hashMap.end()) return false;
                hashMap[board[col][row]]++;
            }
        }

        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            if (!validRow(i, board)) return false;
        }

        for (int j = 0; j < 9; j++) {
            if (!validCol(j, board)) return false;
        }

        if (!check3x3(0, 0, board)) return false;

        if (!check3x3(0, 3, board)) return false;

        if (!check3x3(0, 6, board)) return false;

        if (!check3x3(3, 0, board)) return false;

        if (!check3x3(3, 3, board)) return false;

        if (!check3x3(3, 6, board)) return false;

        if (!check3x3(6, 0, board)) return false;

        if (!check3x3(6, 3, board)) return false;

        if (!check3x3(6, 6, board)) return false;

        return true;
    }
};
