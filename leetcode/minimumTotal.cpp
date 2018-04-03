class Solution {
public:
    int minimumTotal(vector<vector<int> > &tr) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (tr.empty()) return 0;
        int n = tr.size();
        vector<int> cur(n);
        cur[0] = tr[0][0];
        for (int i=1; i<n; ++i) {
            cur[i] = cur[i-1] + tr[i][i];
            for (int j=i-1; j>0; --j) cur[j] = min(cur[j-1], cur[j]) + tr[i][j];            
            cur[0] += tr[i][0];
        }
        int minsum = INT_MAX;
        for (int j=0; j<n; ++j) minsum = min(minsum, cur[j]);
        return minsum;
    }
};
