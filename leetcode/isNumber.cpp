class Solution {
public:
    bool isNumber(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        double f;
        char rest[1000];
        int n;
        if (sscanf(s, "%llf%n%s", &f, &n, rest) != 1) return false;
        if (s[n-1]=='.') {
            if ((n==1)||(!isdigit(s[n-2]))) return false;
        }
        else if (!isdigit(s[n-1])) return false;
        
        return true;
    }
};

