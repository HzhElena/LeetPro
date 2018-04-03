class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!haystack || !needle) return NULL;
        if (*needle == 0) return haystack;
        
        int n = strlen(needle);
        vector<int> P(n);
        P[0] = -1; 
        int k = -1;
        for (int i=1; i<n; ++i) {
            while ((k!=-1) && (needle[i]!=needle[k+1])) k = P[k];
            if (needle[i] == needle[k+1]) ++k;
            P[i] = k;
        }
        
        int m = strlen(haystack);
        k = -1;
        for (int i=0; i<m; ++i) {
            while ((k!=-1) && (haystack[i] != needle[k+1])) k = P[k];
            if (haystack[i] == needle[k+1]) ++k;
            if (k == n-1) return haystack + i - n + 1;
        }
        
        return NULL;
    }
};

