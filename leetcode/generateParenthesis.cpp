class Solution {
public:
    vector<string> generateParenthesis(int n) {
        F.clear();
        return dp(n);
    }
private:
    vector<string> dp(int n) {
        if (n == 0) return vector<string>(1, string(""));
        
        if (F.find(n) != F.end()) return F[n];
        
        const vector<string> &A = dp(n-1);
        for (int i=0; i<A.size(); ++i) F[n].push_back('('+A[i]+')');
        
        for (int k=1; k<n; ++k) {
            const vector<string> &B = dp(k);
            const vector<string> &C = dp(n-k);
            for (int i=0; i<B.size(); ++i) for (int j=0; j<C.size(); ++j)
                F[n].push_back(B[i]+C[j]);
        }
        
        sort(F[n].begin(), F[n].end());
        F[n].erase(unique(F[n].begin(), F[n].end()), F[n].end());
        return F[n];
    }

    unordered_map<int, vector<string> > F;
};

