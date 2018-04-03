class Solution {
public:
    string simplifyPath(string path) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        path = path + '/';
        vector<string> stk;
        for (int i=0, n=path.size(); i<n-1; ) {
            int j = i + 1;
            while (path[j]!='/') ++j;
            string cur = path.substr(i+1, (j-1)-(i+1)+1);
            i = j;
            if (cur.empty() || (cur==".")) continue;
            if (cur == "..") {
                if (!stk.empty()) stk.pop_back();
            }
            else stk.push_back(cur);
        }
        string ans;
        for (int i=0; i<stk.size(); ++i) ans = ans + '/' + stk[i];
        return (ans.empty()) ? "/" : ans;
    }
};
