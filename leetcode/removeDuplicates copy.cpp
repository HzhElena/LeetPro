class Solution {
public:
    int removeDuplicates(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = 0;
        for (int i=0; i<n; ) {
            int j = i;
            while ((j<n) && (A[i]==A[j])) ++j;
            A[m++] = A[i];
            if (i+1 < j) A[m++] = A[i];
            i = j;
        }
        return m;
    }
};

