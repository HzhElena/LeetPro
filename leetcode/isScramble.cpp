class Solution {
public:
    bool isScramble(string _s1, string _s2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s1.size() != s2.size()) return false;
        s1 = _s1; s2 = _s2;
        int n = s1.size();
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) 
            for (int k=0; k<n; ++k) F[i][j][k] = 0;
        return dp(0, n-1, 0, n-1) > 0;
    }
private:
    bool dp(int i, int j, int p, int q) {
        if (i > j) return true;
        if (i == j) return s1[i] == s2[p];
        
        int &ret = F[i][j][p];
        if (ret != 0) return ret > 0;
        ret = -1;
        
        for (int k=i; k<j; ++k) {
            bool sp = dp(i, k, p, p+(k-i)) && dp(k+1, j, p+(k-i)+1, q);
            if (sp) { ret = 1; return true; }
            
            sp = dp(k+1, j, p, p+(j-k-1)) && dp(i, k, p+(j-k), q);
            if (sp) { ret = 1; return true; }
        }
        
        return false;
    }
    int F[100][100][100];
    string s1, s2;
};

