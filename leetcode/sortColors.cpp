class Solution {
public:
    void sortColors(int A[], int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        zero = one = two = 0;
        for (int i=0; i<n; ++i)
            if (A[i] == 0) addZero(A);
            else if (A[i] == 1) addOne(A); 
			else addTwo(A);
    }
private:
    int zero, one, two;
    void addZero(int A[]) { addOne(A); A[zero++] = 0; }
    void addOne(int A[]) { addTwo(A); A[one++] = 1; }
    void addTwo(int A[]) { A[two++] = 2; }
};
