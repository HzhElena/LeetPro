class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        int n = board.size();
        vector<int> row(n, 0), col(row), block(row);
        
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (board[i][j]!='.') {
            int code = board[i][j] - '0';
            code = 1<<(code-1);
            int k = int(i/3) * 3 + int(j/3);
            
            if ((row[i] & code) || (col[j] & code) || (block[k] & code)) return false;
            row[i] += code; 
            col[j] += code;
            block[k] += code;
        }
        return true;
    }
};

