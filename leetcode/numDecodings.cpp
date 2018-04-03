class Solution {
public:
    int numDecodings(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) return 0;
        int n = s.size();
        vector<int> F(n+1);
        F[0] = 1;
        F[1] = (s[0]!='0');
        for (int i=2; i<=n; ++i) {
            F[i] = 0;
            if (s[i-1]!='0') F[i] += F[i-1];
            int two = (s[i-2]-'0') * 10 + (s[i-1]-'0');
            if ((10<=two)&&(two<=26)) F[i] += F[i-2];
        }
        return F[n];
    }
};

