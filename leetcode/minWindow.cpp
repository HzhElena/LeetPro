class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<char, int> tab;
        for (auto ch: T) ++tab[ch];
        
        int minL = INT_MAX, cnt = T.size(), start;
        for (int i=0, j=0, n=S.size(); i<n; ++i) {
            while ((j<n) && (cnt>0)) {
                if (--tab[S[j]] >= 0) --cnt;
                ++j;
            }
            if ((cnt==0) && (j-i<minL)) {
                minL = j - i;
                start = i;
            }
            if (++tab[S[i]] > 0) ++cnt;
        }
        
        return (minL < INT_MAX) ? S.substr(start, minL) : "";
    }
};
