class Solution {
public:
    typedef long long ll;
    int sqrt(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        ll lo = -1, hi = ll(x) + 1;
        while (lo+1<hi) {
            ll mid = (lo + hi) >> 1;
            if (mid*mid<=x) lo = mid; else hi = mid;
        }
        return lo;
    }
};

/*
class Solution {
public:
    typedef long long ll;
    
    int sqrt(int x) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        double t = 1;
        for (;;) {
            double nt = (t + x/t) / 2;
            if (abs(t-nt)<1e-6) break;
            t = nt;
        }
        return (int)(t+1e-9);
    }
};
*/
