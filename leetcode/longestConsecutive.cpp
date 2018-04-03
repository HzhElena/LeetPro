class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        unordered_set<int> tab(num.begin(), num.end());
        int maxL = 0;
        for (int i=0, n=num.size(); i<n; ++i) {
            int lo = num[i], hi = num[i] + 1;
            while (tab.find(lo)!=tab.end()) tab.erase(lo--);
            while (tab.find(hi)!=tab.end()) tab.erase(hi++);
            maxL = max(maxL, hi-lo-1);
        }
        return maxL;
    }
};