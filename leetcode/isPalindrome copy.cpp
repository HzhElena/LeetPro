class Solution {
public:
    bool isPalindrome(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        for (int i=0, j=s.size()-1; i<j; ) {
            while ((i<j)&& !(isdigit(s[i])||isalpha(s[i]))) ++i;
            while ((i<j)&& !(isdigit(s[j])||isalpha(s[j]))) --j;
            if (tolower(s[i++])!=tolower(s[j--])) return false;
        }
        return true;
    }
};

