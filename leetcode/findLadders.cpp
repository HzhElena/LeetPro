class Solution {
public:
    vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        dict.insert(end); dict.insert(start);
        unordered_map<string, int> tab;
        word.clear();
        int m = 0;
        for (decltype(dict.begin()) it=dict.begin(); it!=dict.end(); ++it) {
            tab[*it] = m++;
            word.push_back(*it);
        }
        
        G = vector<vector<int> >(m, vector<int>());
        for (int i=0; i<m; ++i) {
            string str = word[i];
            for (int j=0, len=str.size(); j<len; ++j) {
                char c = str[j];
                for (char ch='a'; ch<='z';++ch) {
                    str[j] = ch;
                    if (dict.find(str)!=dict.end()) {
                        int k = tab[str];
                        G[i].push_back(k);
                    }
                }
                str[j] = c;
            }
        }
        
        dist = vector<int>(m, INT_MAX);
        int s = tab[start], e = tab[end];
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int i = q.front();
            q.pop();
            if (i == e) break;
            
            for (int j=0, n=G[i].size(); j<n; ++j) {
                int k = G[i][j];
                if (dist[k] == INT_MAX) {
                    dist[k] = dist[i] + 1;
                    q.push(k);
                }
            }
        }
        
        ans.clear(); now.clear();
        dfs(e);
        return ans;
    }
private:
    vector<vector<int> > G;
    vector<string> word;
    vector<int> dist;
    vector<vector<string> > ans;
    vector<string> now;
    
    void dfs(int i) {
        now.push_back(word[i]);
        if (dist[i] == 0) {
            ans.push_back(vector<string>(now.rbegin(), now.rend()));
            now.pop_back();
            return;
        }
        
        for (int j=0, n=G[i].size(); j<n; ++j) {
            int k = G[i][j];
            if (dist[k] + 1 == dist[i]) dfs(k);
        }
        now.pop_back();
    }
};

