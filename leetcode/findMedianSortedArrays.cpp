class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int mid = (m+n+1)/2;
        double a = findKth(A, m, B, n, mid);
        if ((m+n)%2 == 0) a = (a + findKth(A, m, B, n, mid+1)) / 2;
        return a;
    }
private:
    double findKth(int A[], int m, int B[], int n, int k) {
        int p = findFirst(A, m, B, n, k);
        return (p >= 0) ? A[p] : B[findFirst(B, n, A, m, k)];
    }
    int findFirst(int A[], int m, int B[], int n, int k) {
        int lo = 0, hi = min(m, k)-1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            int p = k - (mid + 1) - 1;
            if ((p>n-1) || (p>=0) && (B[p] > A[mid])) lo = mid + 1; else
            if ((p<n-1) && (B[p+1]<A[mid])) hi = mid - 1; else 
            return mid;
        }
        return -1;
    }
};

/*
class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int mid = (m+n+1)/2;
        double a = findKth(A, m, B, n, mid);
        if ((m+n)%2 == 0) a = (a + findKth(A, m, B, n, mid+1)) / 2;
        return a;
    }
private:
    double findKth(int A[], int m, int B[], int n, int k) {
        if (m < n) {
            swap(A, B); swap(m, n);
        }
        
        int mid = m / 2;
        int i = -1, j = n;
        while (i+1<j) {
            int s = (i+j) / 2;
            if (B[s] <= A[mid]) i = s; else j = s;
        }
        
        int pos = mid + 1 + i + 1;
        if (pos == k) return A[mid];
        if (pos > k) return findKth(A, mid, B, i+1, k);
        return findKth(A+mid+1, m-mid-1, B+i+1, n-i-1, k-pos);
    }
};
*/
