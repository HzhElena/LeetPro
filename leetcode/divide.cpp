class Solution {
public:
    typedef long long ll;
    int divide(int dividend, int divisor) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ll a = dividend, b = divisor;
        int sign = 1;
        if (a < 0) { sign = -sign; a = -a; }
        if (b < 0) { sign = -sign; b = -b; }
        
        ll c = div(a, b);
        return (int)(sign * c);
    }
private:
    ll div(ll a, ll b) {
        if (a < b) return 0;
        ll c = div(a, b+b) * 2;
        if (a-b*c >= b) ++c;
        return c;
    }
};
