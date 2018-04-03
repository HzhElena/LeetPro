class Solution {
public:
    vector<vector<string> > solveNQueens(int _n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        n = _n;
        tab.clear(); for (int i=0; i<n; ++i) tab[1<<i] = i;
        now = vector<string>(n, string(n, '.'));
        ans.clear();
        nQueen(0, 0, 0, 0);
        return ans;
    }
private:
    void nQueen(int col, int diagL, int diagR, int k) {
        if (k == n) {
            ans.push_back(now);
            return;
        }
        int choice = ~(col|diagL|diagR) & ((1<<n)-1);
        while (choice > 0) {
            int low = choice & (choice^(choice-1));
            int i = tab[low];
            now[k][i] = 'Q';
            nQueen(col+low, (diagL+low)<<1, (diagR+low)>>1, k+1);
            now[k][i] = '.';
            choice -= low;
        }
    }
    unordered_map<int, int> tab;
    vector<vector<string> > ans;
    vector<string> now;
    int n;
};

