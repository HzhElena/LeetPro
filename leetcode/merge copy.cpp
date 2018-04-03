class Solution {
public:
    void merge(int A[], int m, int B[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        for (int i=m+n-1; i>=0; --i) {
            if ((m>0) && ((n<=0)||(A[m-1]>=B[n-1]))) A[i] = A[--m];
            else A[i] = B[--n];
        }
    }
};

