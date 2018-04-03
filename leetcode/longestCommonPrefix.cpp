class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if (strs.empty()) return "";
        
        string sa = strs[0], sb = strs[0];
        for (auto s : strs) 
            if (s < sa) sa = s; 
            else if (s > sb) sb = s;
        
        int n = min(sa.size(), sb.size());
        for (int i=0; i<n; ++i) if (sa[i] != sb[i]) return sa.substr(0, i);
        return sa.substr(0, n);
    }
};
