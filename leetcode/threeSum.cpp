class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        for (int i=0, n=num.size(); i<n; ++i) {
            int j=i+1, k=n-1;
            while (j<k) {
                int sum = num[i] + num[j] + num[k];
                if (sum == 0) {
                    vector<int> now;
                    now.push_back(num[i]);
                    now.push_back(num[j]);
                    now.push_back(num[k]);
                    ans.push_back(now);
                    ++j; --k;
                }
                else if (sum > 0) --k; else ++j;
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};

