class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.empty() || board[0].empty()) return;
        r = board.size(); c = board[0].size();
        
        queue<pair<int, int> > q;
        for (int j=0; j<c; ++j) {
            enque(board, q, 0, j);
            enque(board, q, r-1, j);
        }
        for (int i=0; i<r; ++i) {
            enque(board, q, i, 0);
            enque(board, q, i, c-1);
        }
        while (!q.empty()) {
            int i = q.front().first;
            int j = q.front().second;
            q.pop();
            for (int k=0; k<4; ++k) enque(board, q, i+dx[k], j+dy[k]);
        }
        
        for (int i=0; i<r; ++i) for (int j=0; j<c; ++j) 
            if (board[i][j] == 'O') board[i][j] = 'X';
        for (int i=0; i<r; ++i) for (int j=0; j<c; ++j)
            if (board[i][j] == 'D') board[i][j] = 'O';
    }
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int r, c;
    void enque(vector<vector<char>> &board, queue<pair<int, int>> &q, int i, int j) {
        if ((i<0)||(i>=r)||(j<0)||(j>=c)||(board[i][j]!='O')) return;
        board[i][j] = 'D';
        q.push(make_pair(i, j));
    }
};

