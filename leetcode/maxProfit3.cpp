class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.empty()) return 0;
        int n = prices.size();
        vector<int> L(n, 0), R(n, 0);
        for (int i=1, low=prices[0]; i<n; ++i) {
            L[i] = max(L[i-1], prices[i]-low);
            low = min(low, prices[i]);
        }
        int ret = 0;
        for (int i=n-2, hig=prices[n-1]; i>=0; --i) {
            R[i] = max(R[i+1], hig-prices[i]);
            hig = max(hig, prices[i]);
            ret = max(ret, L[i] + R[i]);
        }
        return ret;
    }
};

