class Solution {
public:
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (a.size() < b.size()) a = a + '0';
        while (a.size() > b.size()) b = b + '0';
        
        a = a + '0'; b = b + '0';
        for (int i=0, carry=0; i<a.size(); ++i) {
            carry += a[i]-'0' + b[i]-'0';
            a[i] = char('0'+(carry&1));
            carry >>= 1;
        }
        
        while ((a.size()>1) && (a.back()=='0')) a.erase(a.end()-1);
        reverse(a.begin(), a.end());
        return a;
    }
};

