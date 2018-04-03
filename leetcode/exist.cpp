class Solution {
public:
    bool exist(vector<vector<char> > &_board, string _word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        board = _board; word = _word;
        r = board.size(); c = board[0].size();
        used = vector<vector<bool> > (r, vector<bool>(c, false));
        
        n = word.size();
        for (int i=0; i<r; ++i) for (int j=0; j<c; ++j)
            if (dfs(i, j, 0)) return true;
        return false;
    }
private:
    vector<vector<char> > board;
    string word;
    vector<vector<bool> > used;
    int r, c, n;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    
    bool dfs(int i, int j, int k) {
        if (k == n) return true;
        if ((i<0)||(i>=r)||(j<0)||(j>=c)
            || used[i][j] || (board[i][j]!=word[k])) return false;
        used[i][j] = true;
        for (int d=0; d<4; ++d) if (dfs(i+dx[d], j+dy[d], k+1)) return true;
        used[i][j] = false;
        return false;
    }
};

