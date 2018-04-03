class Solution {
public:
    string intToRoman(int num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function    
        string s;
        int k = num;
        
        if (k >= 1000) s = s + roman(k/1000, 'M', 'M', 'M');
        k %= 1000;
        
        if (k >= 100) s = s + roman(k/100, 'C', 'D', 'M');
        k %= 100;
        
        if (k >= 10) s = s + roman(k/10, 'X', 'L', 'C');
        k %=10;
        
        if (k >= 1) s = s + roman(k, 'I', 'V', 'X');
        return s;
    }
private:
    string roman(int k, char one, char five, char ten) {
        if (k == 0) return string("");
        if (k <= 3) return string(k, one);
        if (k == 4) return string(1, one) + five;
        if (k <= 8) return string(1, five) + string(k-5, one);
        return string(1, one) + ten;
    }
};

