class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        A.clear();
        sort(num.begin(), num.end());
        for (int i=0, n=num.size(); i<n; ) {
            int j=i;
            while ((j<n)&&(num[i]==num[j]))++j;
            A.push_back(make_pair(num[i], j-i));
            i = j;
        }
        
        ans.clear(); now.clear();
        dp(target, A.size());
        return ans;
    }
private:
    void dp(int sum, int n) {
        if (n == 0) {
            if (sum == 0) ans.push_back(vector<int>(now.rbegin(), now.rend()));
            return;
        }
        if (sum < 0) return;
        
        dp(sum, n-1);
        int m = A[n-1].second;
        for (int i=0; i<m; ++i) {
            now.push_back(A[n-1].first);
            sum -= A[n-1].first;
            dp(sum, n-1);
        }
        now.erase(now.end()-m, now.end());
    }

    vector<pair<int, int> > A;
    vector<vector<int> > ans;
    vector<int> now;
};

