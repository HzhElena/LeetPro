class Solution {
public:
    int trap(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 0;
        vector<int> L(n), R(n);
        L[0] = A[0];
        for (int i=1; i<n; ++i) L[i] = max(L[i-1], A[i]);
        
        R[n-1] = A[n-1];
        for (int i=n-2; i>=0; --i) R[i] = max(R[i+1], A[i]);
        
        int ret = 0;
        for (int i=0; i<n; ++i) ret += min(L[i], R[i]) - A[i];
        return ret;
    }
};

