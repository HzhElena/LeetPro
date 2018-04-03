class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        reverse(digits.begin(), digits.end());
        int carry = 1;
        for (int i=0; i<digits.size(); ++i) {
            carry += digits[i];
            digits[i] = carry % 10;
            carry /= 10;
        }
        if (carry > 0) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};

