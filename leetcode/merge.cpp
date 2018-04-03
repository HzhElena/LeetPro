/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval> &A) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<pair<int, int> > B;
        for (int i=0; i<A.size(); ++i) B.push_back(make_pair(A[i].start, A[i].end));
        sort(B.begin(), B.end());
        
        vector<Interval> ans;
        for (int i=0, n=B.size(); i<n; ) {
            int R = B[i].second, j = i;
            while ((j<n) && (R >= B[j].first)) R = max(R, B[j++].second);
            ans.push_back(Interval(B[i].first, R));
            i = j;
        }
        return ans;
    }
};

