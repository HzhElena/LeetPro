class Solution {
public:
    int uniquePaths(int m, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if ((m<=0) || (n<=0)) return 0;
        vector<vector<int> > F(m, vector<int>(n, 0));
        F[0][0] = 1;
        for (int j=1; j<n; ++j) F[0][j] = 1;
        for (int i=1; i<m; ++i) {
            F[i][0] = 1;
            for (int j=1; j<n; ++j)
                F[i][j] = F[i][j-1] + F[i-1][j];
        }
        return F[m-1][n-1];
    }
};

