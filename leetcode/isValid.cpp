class Solution {
public:
    bool isValid(string s) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        vector<char> stk;
        for (int i=0; i<s.size(); ++i) {
            if ((s[i]=='(')||(s[i]=='[')||(s[i]=='{')) stk.push_back(s[i]);
            else {
                if (stk.empty()) return false;
                if ((s[i]==')') && (stk.back()=='(') ||
                    (s[i]==']') && (stk.back()=='[') ||
                    (s[i]=='}') && (stk.back()=='{')) stk.pop_back();
                else return false;
            }
        }
        return stk.empty();
    }
};

/*
class Solution {
public:
    bool isValid(string _s) {
        s = _s;
        int n = s.size();
        F = vector<vector<int> >(n, vector<int>(n, -1));
        return dp(0, n-1);
    }
private:
    bool dp(int i, int j) {
        if (i > j) return true;
        
        int &ret = F[i][j];
        if (ret >= 0) return (ret == 1);
        ret = 0;
        
        if ((s[i]=='(') && (s[j]==')') || (s[i]=='{') && (s[j]=='}')
            || (s[i]=='[') && (s[j]==']')) 
            if (dp(i+1, j-1)) { 
                ret = 1; 
                return true; 
            }
        
        for (int k=i; k<j; ++k) if (dp(i, k) && dp(k+1, j)) {
            ret = 1; break;
        }
        
        return (ret == 1);
    }
    
    vector<vector<int> > F;
    string s;
};
*/
