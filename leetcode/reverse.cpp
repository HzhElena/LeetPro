class Solution {
public:
    int reverse(int x) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int sign = 1;
        if (x < 0) { x = -x; sign = -1; }
        
        int y = 0;
        while (x > 0) {
            y = y * 10 + (x%10);
            x /= 10;
        }
        return sign * y;
    }
};
