class Solution {
public:
    int minCut(string _s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        s = _s; n = s.size();
        isP = vector<vector<bool> >(n, vector<bool>(n, false));
        for (int c=0; c<n; ++c) {
            extend(c, c);
            extend(c, c+1);
        }
        
        vector<int> F(n+1, n);
        F[0] = 0;
        for (int i=1; i<=n; ++i)
            for (int j=0; j<i; ++j) if (isP[j][i-1]) F[i] = min(F[i], F[j]+1);
        return max(0, F[n]-1);
    }
private:
    vector<vector<bool> > isP;
    string s;
    int n;
    
    void extend(int i, int j) {
        while ((i>=0)&&(j<n)&&(s[i]==s[j])) isP[i--][j++] = true;
    }
};

