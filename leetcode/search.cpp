class Solution {
public:
    int search(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int lo = 0, hi = n-1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (A[mid] == target) return mid;
            if (A[lo] <= A[mid]) {
                if ((A[lo]<=target) && (target<=A[mid])) hi = mid - 1;
                else lo = mid + 1;
            }
            else {
                if ((A[mid]<=target) && (target<=A[hi])) lo = mid + 1;
                else hi = mid - 1;
            }
        }
        
        return -1;
    }
};

