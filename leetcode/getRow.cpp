class Solution {
public:
    vector<int> getRow(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> pre(n+1), now(n+1);
        now[0] = 1;
        for (int i=0; i<n; ++i) {
            pre = now;
            for (int j=1; j<=i; ++j) now[j] = pre[j-1] + pre[j];
            now[i+1] = 1;
        }
        return now;
    }
};

