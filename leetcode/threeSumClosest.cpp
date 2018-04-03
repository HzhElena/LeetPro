class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        sort(num.begin(), num.end());
        int minDiff = INT_MAX, ret;
        for (int i=0, n=num.size(); i<n; ++i) {
            int j=i+1, k=n-1;
            while (j<k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == target) return sum;
                
                int diff = sum - target;
                if (diff < 0) diff = -diff;
                if (diff < minDiff) {
                    minDiff = diff;
                    ret = sum;
                }
                
                if (sum > target) --k; else ++j;
            }
        }
        return ret;
    }
};

