class Solution {
public:
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        int n = num1.size(), m = num2.size();
        
        vector<int> C(n+m);
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) C[i+j] += (num1[i]-'0')*(num2[j]-'0');
        
        string ans;
        for (int i=0; i<n+m; ++i) {
            if (C[i]>=10) C[i+1] += C[i]/10;
            ans = char('0'+(C[i]%10)) + ans;
        }
        while ((ans.size()>1)&&(ans[0]=='0')) ans.erase(0, 1);
        
        return ans;
    }
};

