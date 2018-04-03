class Solution {
public:
    string countAndSay(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        string s = "1";
        for (int i=1; i<n; ++i) {
            string ns;
            for (int j=0, m=s.size(); j<m;){
                int k = j;
                while ((k<m)&&(s[j]==s[k])) ++k;
                ns += to_string(k-j) + s[j];
                j = k;
            }
            s = ns;
        }
        return s;
    }
};