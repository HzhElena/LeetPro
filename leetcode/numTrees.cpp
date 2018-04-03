// Can speed up to O(N).
class Solution {
public:
    int numTrees(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> C(n+1, 0);
        C[0] = 1;
        for (int i=1; i<=n; ++i) for (int j=0; j<i; ++j) C[i] += C[j] * C[i-1-j];
        return C[n];
    }
};

