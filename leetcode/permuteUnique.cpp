class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > ans;
        sort(num.begin(), num.end());
        do {
            ans.push_back(num);
        } while (next_permutation(num.begin(), num.end()));
        return ans;
    }
};

