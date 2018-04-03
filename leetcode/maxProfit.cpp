class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (prices.empty()) return 0;
        int maxp = 0, low = prices[0];
        for (int i=1, n=prices.size(); i<n; ++i) {
            maxp = max(maxp, prices[i] - low);
            low = min(low, prices[i]);
        }
        return maxp;
    }
};
