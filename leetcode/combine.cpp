class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ans.clear(); 
        now = vector<int>(k);
        dfs(n, k);
        return ans;
    }
private:
    vector<vector<int> > ans;
    vector<int> now;
    
    void dfs(int n, int k) {
        if (k == 0) {
            ans.push_back(now);
            return;
        }
        if (n > k) dfs(n-1, k);
        now[k-1] = n;
        dfs(n-1, k-1);
    }
};
