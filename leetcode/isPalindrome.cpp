class Solution {
public:
    typedef long long ll;
    bool isPalindrome(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (x < 0) return false;
        ll a = x, b = 0;
        while (a > 0) {
            b = b * 10 + (a%10);
            a /= 10;
        }
        return (x == b);
    }
};

