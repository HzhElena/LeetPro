class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int n = s.size();
        ans.clear();
        
        for (int i=0; i<n; ++i) {
            string sa = s.substr(0, i+1);
            if (!valid(sa)) break;
            for (int j=i+1; j<n; ++j) {
                string sb = s.substr(i+1, j-i);
                if (!valid(sb)) break;
                for (int k=j+1; k+1<n; ++k) {
                    string sc = s.substr(j+1, k-j);
                    string sd = s.substr(k+1, n-k);
                    if (valid(sc) && valid(sd)) ans.push_back(sa+ '.'+sb+'.'+sc+'.'+sd);
                }
            }
        }
        
        return ans;
    }
private:
    vector<string> ans;
    
    bool valid(string& num) {
        if (num.size() >= 4) return false;
        if ((num.size()>1) && (num[0]=='0')) return false;
        return atoi(num.c_str()) <= 255;
    }
};

