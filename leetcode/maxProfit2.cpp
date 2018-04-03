class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int ret = 0;
        for (int i=1, n=prices.size(); i<n; ++i)
            ret += max(0, prices[i]-prices[i-1]);
        return ret;
    }
};

