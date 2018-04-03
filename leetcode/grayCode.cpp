class Solution {
public:
    vector<int> grayCode(int n) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<int> ans;
        for (int k=0, m=1<<n; k<m; ++k) ans.push_back(k^(k>>1));
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> gray(1, 0);
        for (int i=1; i<=n; ++i) {
            vector<int> next(gray.rbegin(), gray.rend());
            int delta = 1 << (i-1);
            for (int j=0; j<next.size(); ++j) gray.push_back(next[j]+delta);
        }
        return gray;
    }
};
*/
