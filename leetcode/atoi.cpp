class Solution {
public:
    typedef long long ll;
    int atoi(const char *str) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!str) return 0;
        while (*str==' ') ++str;
        
        int sign = 1;
        if (*str=='-') sign = -sign;
        if ((*str=='+')||(*str=='-')) ++str;
        
        ll val = 0;
        while (isdigit(*str)) {
            val = val*10 + (*str - '0');
            if (val >= INT_MAX) break;
            ++str;
        }
        
        val *= sign;
        if (val >= INT_MAX) return INT_MAX;
        if (val <= INT_MIN) return INT_MIN;
        return (int)val;
    }
};

