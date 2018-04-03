class Solution {
public:
    int maxArea(vector<int> &height) {
        int area = dp(height);
        reverse(height.begin(), height.end());
        return max(area, dp(height));
    }
private:
    int dp(vector<int> &height) {
        int n = height.size(), area = 0;
        vector<int> stk;
        for (int i=0; i<n; ++i) {
            int lo = -1, hi = stk.size();
            while (lo+1<hi) {
                int mid = (lo + hi) / 2;
                if (height[stk[mid]] < height[i]) lo = mid; else hi = mid;
            }
            if (hi < stk.size()) {
                area = max(area, height[i] * (i - stk[hi]));
            }
            else stk.push_back(i);
        }
        return area;
    }
};

