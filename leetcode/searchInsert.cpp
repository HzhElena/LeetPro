class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lo = -1, hi = n;
        while (lo+1<hi) {
            int mid = (lo + hi) / 2;
            if (A[mid] < target) lo = mid; else hi = mid;
        }
        return lo+1;
    }
};

