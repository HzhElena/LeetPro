class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        unordered_map<int, vector<pair<int, int> > > pairSum;
        int n = num.size();
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            int sum = num[i] + num[j];
            pairSum[sum].push_back(make_pair(i, j));
        }
        
        vector<vector<int> > ans;
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            int key = target - num[i] - num[j];
            if (pairSum.find(key) == pairSum.end()) continue;
            
            vector<pair<int, int> > &arr = pairSum[key];
            for (int k=0, m=arr.size(); k<m; ++k) if (j < arr[k].first) {
                vector<int> now;
                now.push_back(num[i]);
                now.push_back(num[j]);
                now.push_back(num[arr[k].first]);
                now.push_back(num[arr[k].second]);
                ans.push_back(now);
            }
        }
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        
        return ans;
    }
};

