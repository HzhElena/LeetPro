class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int n = ratings.size();
        
        vector<int> B(n, 1);
        for (int i=1; i<n; ++i)
            if (ratings[i] > ratings[i-1]) B[i] = max(B[i], B[i-1]+1);
        for (int i=n-2; i>=0; --i)
            if (ratings[i] > ratings[i+1]) B[i] = max(B[i], B[i+1]+1);
        
        int ret = 0;
        for (int i=0; i<n; ++i) ret += B[i];
        return ret;
    }
};
