class Solution {
public:
    vector<vector<string>> partition(string _s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        s = _s; n = s.size();
        isP = vector<vector<bool> >(n, vector<bool>(n, false));
        
        for (int c=0; c<n; ++c) {
            extend(c, c);
            extend(c, c+1);
        }
        
        F = vector<bool> (n+1, false);
        F[0] = true;
        for (int i=1; i<=n; ++i)
            for (int j=0; j<i; ++j) F[i] = F[i] || (F[j] && isP[j][i-1]);
        
        ans.clear(); now.clear();
        dp(n);
        
        return ans;
    }
private:
    vector<vector<bool> > isP;
    vector<bool> F;
    string s;
    int n;
    vector<vector<string> > ans;
    vector<string> now;
    
    void extend(int i, int j) {
        while ((i>=0) && (j<n)) {
            if (s[i]!=s[j]) return;
            isP[i][j] = true;
            --i; ++j;
        }
    }
    
    void dp(int i) {
        if (i == 0) {
            ans.push_back(vector<string>(now.rbegin(), now.rend()));
            return;
        }
        
        for (int j=0; j<i; ++j) if (F[j] && isP[j][i-1]) {
            now.push_back(s.substr(j, i-j));
            dp(j);
            now.pop_back();
        }
    }
};

