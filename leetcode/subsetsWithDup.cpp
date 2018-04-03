class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        tab.clear();
        sort(S.begin(), S.end());
        for (int i=0, n=S.size(); i<n; ) {
            int j = i;
            while ((j<n) && (S[j]==S[i])) ++j;
            tab.push_back(make_pair(S[i], j-i));
            i = j;
        }
        ans.clear(); now.clear();
        dp(0);
        return ans;
    }
private:
    void dp(int k) {
        if (k == tab.size()) {
            ans.push_back(now);
            return;
        }
        dp(k+1);
        for (int i=1, n=tab[k].second; i<=n; ++i) {
            now.push_back(tab[k].first);
            dp(k+1);
        }
        now.erase(now.end()-tab[k].second, now.end());
    }

    vector<pair<int, int> > tab;
    vector<int> now;
    vector<vector<int> > ans;
};

