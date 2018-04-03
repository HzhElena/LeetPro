class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = s.size();
        vector<bool> F(n+1, false);
        F[0] = true;
        for (int i=1; i<=n; ++i) {
            string tail;
            for (int j=i-1; j>=0; --j) {
                tail = s[j] + tail;
                if (F[j] && (dict.find(tail)!=dict.end())) {
                    F[i] = true;
                    break;
                }
            }
        }
        return F[n];
    }
};

