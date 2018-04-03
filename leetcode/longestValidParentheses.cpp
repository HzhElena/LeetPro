class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = s.size(), maxL = 0;
        vector<int> F(n, 0);
        for (int i=n-2; i>=0; --i) if (s[i]=='(') {
            int j = i + F[i+1] + 1;
            if ((j<n) && (s[j]==')')) {
                F[i] = F[i+1] + 2;
                if (j+1<n) F[i] += F[j+1];
            }
            maxL = max(maxL, F[i]);
        }
        return maxL;
    }
};

