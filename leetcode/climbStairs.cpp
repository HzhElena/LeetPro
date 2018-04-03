class Solution {
public:
    int climbStairs(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 0) return 1;
        vector<int> F(n+1);
        F[0] = F[1] = 1;
        for (int i=2; i<=n; ++i) F[i] = F[i-1] + F[i-2];
        return F[n];
    }
};

