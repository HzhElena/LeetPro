class Solution {
public:
    string getPermutation(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        vector<int> P(9);
        P[0] = 1;
        for (int i=1; i<n; ++i) P[i] = P[i-1] * i;
        
        string seq;
        for (int i=0; i<n; ++i) seq = seq + char('1' + i);  
        --k;
        for (int i=0; i<n; ++i) {
            sort(seq.begin()+i, seq.end());
            int j= k / P[n-1-i];
            k %= P[n-1-i];
            swap(seq[i], seq[i+j]);
        }
        return seq;
    }
};

