class Solution {
public:
    int largestRectangleArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int n = height.size();
        vector<int> left(n), right(n), stk;
        
        for (int i=0; i<n; ++i) {
            left[i] = i;
            while ((!stk.empty()) && (height[stk.back()]>=height[i])) {
                left[i] = left[stk.back()];
                stk.pop_back();
            }
            stk.push_back(i);
        }
        stk.clear();
        for (int i=n-1; i>=0; --i) {
            right[i] = i;
            while ((!stk.empty()) && (height[stk.back()]>=height[i])) {
                right[i] = right[stk.back()];
                stk.pop_back();
            }
            stk.push_back(i);
        }
        
        int maxArea = 0;
        for (int i=0; i<n; ++i) {
            int area = height[i] * (right[i] - left[i] + 1);
            if (area > maxArea) maxArea = area;
        }
        return maxArea;
    }
};
