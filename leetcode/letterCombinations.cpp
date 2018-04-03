class Solution {
public:
    vector<string> letterCombinations(string _digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        digits = _digits;
        ans.clear();
        
        string s(digits);
        dfs(digits.size()-1, s);
        return ans;
    }
private:
    string digToCh[10] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    string digits;
    vector<string> ans;
    
    void dfs(int i, string &s) {
        if (i < 0) {
            ans.push_back(s);
            return;
        }
        
        string &code = digToCh[(int)(digits[i]-'0')];
        for (int j=0; j<code.size(); ++j) {
            s[i] = code[j];
            dfs(i-1, s);
        }
    }
};

