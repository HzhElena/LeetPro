class Solution {
public:
    string convert(string s, int nRows) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        if (nRows <= 1) return s;
        int n = s.size();
        
        string ans;
        for (int i=0; i<nRows; ++i) {
            if ((i==0)||(i+1==nRows)) {
                for (int j=i; j<n; j+=2*nRows-2) ans += s[j];
            }
            else {
                for (int j=i; j<n; j+=2*nRows-2) {
                    ans += s[j];
                    int k = (j-i) + (2*nRows-2-i);
                    if (k<n) ans += s[k];
                }
            }
        }
        return ans;
    }
};

