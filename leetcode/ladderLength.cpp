class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        dict.insert(end);
        queue<pair<string, int> > pq;
        pq.push(make_pair(start, 1));
        while (!pq.empty()) {
            string cur = pq.front().first;
            int d = pq.front().second;
            pq.pop();
            if (cur == end) return d;
            
            for (int i=0, n=cur.size(); i<n; ++i) {
                char ch = cur[i];
                for (char c='a'; c<='z'; ++c) {
                    cur[i] = c;
                    if (dict.find(cur)==dict.end()) continue;
                    pq.push(make_pair(cur, d+1));
                    dict.erase(cur);
                }
                cur[i] = ch;
            }
        }
        return 0;
    }
};
