class Solution {
public:
    int minDistance(string word1, string word2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = word1.size(), m = word2.size();
        vector<vector<int> > F(n+1, vector<int>(m+1));
        F[0][0] = 0;
        for (int j=1; j<=m; ++j) F[0][j] = j;
        for (int i=1; i<=n; ++i) {
            F[i][0] = i;
            for (int j=1; j<=m; ++j) {
                F[i][j] = min(F[i][j-1], F[i-1][j]) + 1;
                F[i][j] = min(F[i][j], F[i-1][j-1]+1);
                if (word1[i-1]==word2[j-1]) F[i][j] = min(F[i][j], F[i-1][j-1]);
            }
        }
        return F[n][m];
    }
};

