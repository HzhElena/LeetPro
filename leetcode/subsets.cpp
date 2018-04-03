class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ans;
        int n = S.size(), all = (1<<n) - 1;
        sort(S.begin(), S.end());
        for (int k=0; k<=all; ++k) {
            vector<int> subset;
            for (int i=0; i<n; ++i) if (k&(1<<i)) subset.push_back(S[i]);
            ans.push_back(subset);
        }
        return ans;
    }
};

