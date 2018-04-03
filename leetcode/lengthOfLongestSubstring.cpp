class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        unordered_set<char> used;
        int len = 0;
        for (int i=0, j=0, n=s.size(); i<n; ++i) {
            while ((j<n)&& (used.find(s[j])==used.end()))
                used.insert(s[j++]);
            len = max(len, j-i);
            used.erase(s[i]);
        }
        return len;
    }
};

