class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        unordered_map<int, int> tab;
        int n = numbers.size();
        for (int i=0; i<n; ++i) tab[numbers[i]] = i;
        
        vector<int> ans;
        for (int i=0; i<n; ++i) {
            int key = target - numbers[i];
            if (tab.find(key) == tab.end()) continue;
            int j = tab[key];
            
            if (j == i) continue;
            ans.push_back(i+1);
            ans.push_back(j+1);
            break;
        }
        return ans;
    }
};

