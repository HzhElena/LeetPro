class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &_cand, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        cand = _cand;
        sort(cand.begin(), cand.end());
        cand.erase(unique(cand.begin(), cand.end()), cand.end());
        
        int n = cand.size();
        F = vector<bool>(target+1, false);
        F[0] = true;
        for (int i=1; i<=target; ++i) for (int j=0; (j<n)&&(i>=cand[j]); ++j)
            F[i] = F[i] || F[i-cand[j]];
        
        ans.clear(); now.clear();
        dp(target, n-1);
        return ans;
    }
private:
    vector<bool> F;
    vector<int> cand, now;
    vector<vector<int> > ans;
    
    void dp(int target, int k) {
        if (target == 0) {
            ans.push_back(vector<int>(now.rbegin(), now.rend()));
            return;
        }
        if (k < 0) return;
        dp(target, k-1);
        if ((target >= cand[k]) && F[target-cand[k]]) {
            now.push_back(cand[k]);
            dp(target-cand[k], k);
            now.pop_back();
        }
    }
};

