class Solution {
public:
    int numDistinct(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = S.size(), m = T.size();
        vector<vector<int> > F(n+1, vector<int>(m+1, 0));
        F[0][0] = 1;
        for (int i=1; i<=n; ++i) {
            F[i][0] = 1;
            for (int j=1; j<=m; ++j) {
                F[i][j] = F[i-1][j];
                if (S[i-1] == T[j-1]) F[i][j] += F[i-1][j-1];
            }
        }
        return F[n][m];
    }
};

