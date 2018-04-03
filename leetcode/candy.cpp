class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
        int n = ratings.size();
        vector<vector<int> > G(n, vector<int>());
        for (int i=0; i<n-1; ++i) {
            int a = ratings[i];
            int b = ratings[i+1];
            if (a > b) G[i+1].push_back(i);
            if (a < b) G[i].push_back(i+1);
        }
        
        vector<int> inDegree(n, 0);
        for (int i=0; i<n; ++i) for (int j=0; j<G[i].size(); ++j) ++inDegree[G[i][j]];
        
        vector<int> dist(n, 0);
        queue<int> q;
        for (int i=0; i<n; ++i) if (inDegree[i]==0) q.push(i);
        
        int ret = 0;
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            ret += dist[i] + 1;
            
            for (int j=0; j<G[i].size(); ++j) {
                int k = G[i][j];
                if (--inDegree[k] == 0) {
                    q.push(k);
                    dist[k] = dist[i] + 1;
                }
            }
        }
        
        return ret;
    }
};

