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
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        int l = newInterval.start, r = newInterval.end, n = intervals.size();
        vector<Interval> ans;
        for (int i=0; i<n; ++i) 
            if (intervals[i].end < l) {
                ans.push_back(intervals[i]);
            }
            else if (intervals[i].start > r) {
                ans.push_back(Interval(l, r));
                ans.insert(ans.end(), intervals.begin()+i, intervals.end());
                return ans;
            }
            else {
                l = min(l, intervals[i].start);
                r = max(r, intervals[i].end);
            }
        ans.push_back(Interval(l, r));
        return ans;
    }
};

