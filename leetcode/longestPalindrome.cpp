class Solution {
public:
    string longestPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return dp(s);
    }
private:
    string dp(string &s) {
        string str("^");
        int n = s.size();
        for (int i=0; i<n; ++i) str = str + '#' + s[i];
        str = str + "#$";
        
        n = str.size();
        vector<int> F(n);
        int c = 0, cLen = 0;
        for (int i=1; i<n-1; ++i) {
            int mirror_i = c - (i - c);
            int R = (mirror_i >= 0) ? min(i+F[mirror_i], c+cLen) : i;
            
            int len = R - i;
            while (str[i-len-1] == str[i+len+1]) ++len;
            F[i] = len;
            if (i+len > c+cLen) {
                c = i;
                cLen = len;
            }
        }
        
        cLen = 0;
        for (int i=1; i<n-1; ++i) if (cLen < F[i]) {
            c = i; cLen = F[i];
        }
        return s.substr((c-cLen-1)/2, cLen);
    }
};

