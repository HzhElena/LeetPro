class Solution {
public:
    int totalNQueens(int _n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        cnt = 0; n = _n;
        nQueen(0, 0, 0, 0);
        return cnt;
    }
private:
    int cnt, n;
    
    void nQueen(int col, int diagL, int diagR, int k){
        if (k == n) { ++cnt; return; }
        int choice = ~(col | diagL | diagR) & ((1<<n)-1);
        while (choice > 0) {
            int low = choice & (choice^(choice-1));
            nQueen(col|low, (diagL|low)<<1, (diagR|low)>>1, k+1);
            choice -= low;
        }
    }
};

