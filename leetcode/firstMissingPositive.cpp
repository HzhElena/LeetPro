class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        for (int i=0; i<n; ++i) if (A[i]!=i+1) {
            int j = A[i] - 1;
            if ((0<=j)&&(j<n)&&(A[j]!=j+1)) swap(A[i], A[j]), --i;
        }
        for (int i=0; i<n; ++i) if (A[i]!=i+1) return i+1;
        return n+1;
    }
};

