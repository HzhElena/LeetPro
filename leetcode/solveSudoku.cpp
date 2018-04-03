class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        row = vector<int>(9, 0); col = row; piece = row;
        for (int i=0; i<9; ++i) for (int j=0; j<9; ++j) if (board[i][j]!='.') {
            int digit = board[i][j] - '1';
            row[i] |= 1<<digit;
            col[j] |= 1<<digit;
            piece[(int)(i/3)*3+(int)(j/3)] |= 1<<digit;
        }
        for (int i=0; i<9; ++i) getID[1<<i] = i;
        dfs(board, 0, 0);
    }
private:
    vector<int> row, col, piece;
    unordered_map<int, int> getID;
    
    bool dfs(vector<vector<char> > &board, int i, int j) {
        if (i == 9) return true;
        
        if (board[i][j]!='.') {
            if (j<8) return dfs(board, i, j+1);
            return dfs(board, i+1, 0);
        }
        
        int k = (int)(i/3)*3+(int)(j/3);
        int choices = ~(row[i]|col[j]|piece[k]) & 511;
        bool flag = false;
        while (choices > 0) {
            int low = choices & (choices ^ (choices-1));
            int digit = getID[low];
            board[i][j] = char('1'+digit);
            row[i] |= low;
            col[j] |= low;
            piece[k] |= low;
            
            flag = (j<8) ? dfs(board, i, j+1) : dfs(board, i+1, 0);
            if (flag) return true;
            
            row[i] -= low;
            col[j] -= low;
            piece[k] -= low;
            choices -= low;
        }
        board[i][j] = '.';
        
        return false;
    }
};

