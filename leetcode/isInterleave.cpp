class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        int n=s1.size(), m=s2.size();
        if (n+m != s3.size()) return false;
        vector<vector<bool> > F(n+1, vector<bool>(m+1, false));
        F[0][0] = true;
        for (int j=1; j<=m; ++j) F[0][j] = (F[0][j-1] && (s3[j-1]==s2[j-1]));
        for (int i=1; i<=n; ++i) {
            F[i][0] = (F[i-1][0] && (s1[i-1]==s3[i-1]));
            for (int j=1; j<=m; ++j)
                F[i][j] = (F[i-1][j] && (s1[i-1]==s3[i+j-1])) || (F[i][j-1] && (s2[j-1]==s3[i+j-1]));
        }
        return F[n][m];
    }
};

