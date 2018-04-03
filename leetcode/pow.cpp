class Solution {
public:
    double pow(double x, int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        return _pow(x, n);
    }
private:
    double _pow(double x, long long n) {
        if (n < 0) return 1 / _pow(x, -n);
        if (n == 0) return abs(x) < 1e-9 ? 0 : 1;
        
        double x2 = _pow(x*x, n/2);
        if (n&1) x2 *= x;
        return x2;
    }
};
