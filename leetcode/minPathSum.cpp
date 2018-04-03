class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (grid.empty()||grid[0].empty()) return 0;
        int r=grid.size(), c=grid[0].size();
        vector<vector<int> > F(r, vector<int>(c));
        F[0][0] = grid[0][0];
        for (int j=1; j<c; ++j) F[0][j] = F[0][j-1] + grid[0][j];
        for (int i=1; i<r; ++i) {
            F[i][0] = F[i-1][0] + grid[i][0];
            for (int j=1; j<c; ++j)
                F[i][j] = min(F[i-1][j], F[i][j-1]) + grid[i][j];
        }
        return F[r-1][c-1];
    }
};

