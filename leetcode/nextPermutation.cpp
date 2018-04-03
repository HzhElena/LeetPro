class Solution {
public:
    void nextPermutation(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.empty()) return;
        for (int i=num.size()-2, maxVal=num.back(); i>=0; --i) {
            if (num[i] >= maxVal) {
                maxVal = num[i];
                continue;
            }
            sort(num.begin()+i+1, num.end());
            for (int j=i+1;;++j) if (num[j] > num[i]) {
                swap(num[i], num[j]);
                break;
            }
            sort(num.begin()+i+1, num.end());
            return;
        }
        sort(num.begin(), num.end());
    }
};

