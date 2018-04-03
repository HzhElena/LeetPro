class Solution {
public:
    int maxSubArray(int A[], int n) {
        return dp(A, 0, n-1);
    }
private:
    int dp(int A[], int lo, int hi) {
        if (lo == hi) return A[lo];
        int mid = (lo + hi) / 2;
        
        int lmax = dp(A, lo, mid);
        int rmax = dp(A, mid+1, hi);
        
        int sum = 0, lsum = INT_MIN, rsum = INT_MIN;
        for (int i=mid+1; i<=hi; ++i) {
            sum += A[i];
            rsum = max(rsum, sum);
        }
        sum = 0;
        for (int i=mid; i>=lo; --i) {
            sum += A[i];
            lsum = max(lsum, sum);
        }
        int ret = max(lmax, rmax);
        ret = max(ret, lsum+rsum);
        return ret;
    }
/*
    int maxSubArray(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = A[0], sum = A[0];
        for (int i=1; i<n; ++i) {
            sum = max(sum, 0) + A[i];
            ret = max(ret, sum);
        }
        return ret;
    }
*/
};

