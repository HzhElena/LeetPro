class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        if (L.empty()) return ans;
        int n = S.size(), m = L.size(), len = L[0].size();
        unordered_map<string, int> tab;
        for (int i=0; i<m; ++i) ++tab[L[i]];
        
        for (int i=0; i<len; ++i) {
            int last = (n-1-i)/len;
            if (last < m-1) continue;
            
            int need = m;
            for (int j=0; j<m-1; ++j) {
                if (--tab[S.substr(i+len*j, len)] >= 0) --need;
            }
            for (int j=m-1; j<=last; ++j) {
                if (--tab[S.substr(i+len*j, len)] >= 0) --need;
                
                int k = j - (m-1);
                if (need == 0) ans.push_back(i+len*k);
                if (++tab[S.substr(i+len*k, len)] > 0) ++need;
            }
            for (int j=last-(m-1)+1; j<=last; ++j) ++tab[S.substr(i+len*j, len)];
        }
        
        return ans;
    }
};

