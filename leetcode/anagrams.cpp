class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<string, vector<int> > hash;
        
        for (int i=0, n=strs.size(); i<n; ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());
            hash[key].push_back(i);
        }
        
        vector<string> ans;
        for (decltype(hash.begin()) it=hash.begin(); it!=hash.end(); ++it) {
            vector<int> &arr = it->second;
            if (arr.size() <= 1) continue;
            for (int i=0, n=arr.size(); i<n; ++i) ans.push_back(strs[arr[i]]);
        }
        return ans;
    }
};

