class Solution {
public:
    int lengthOfLastWord(const char *s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        int last = 0;
        while (*s) {
            if (*s == ' ') ++s;
            else {
                last = 0;
                while (isalpha(*s)) {
                    ++last;
                    ++s;
                }
            }
        }
        return last;
    }
};

