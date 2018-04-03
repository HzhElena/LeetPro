class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (!s || !p) return false;
        if (!*p) return *s == *p;
        
        if (*(p+1)!='*') {
            return ((*s==*p) || (*s)&&(*p=='.')) && isMatch(s+1, p+1);
        }
        
        while (*s) {
            if (isMatch(s, p+2)) return true;
            if ((*s!=*p) && (*p!='.')) break;
            ++s;
        }
        return isMatch(s, p+2);
    }
};

