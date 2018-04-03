class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty() || matrix[0].empty()) return;
        int n = matrix.size(), m = n / 2;
        
        for (int i=0; i<m; ++i) for (int j=0; j<m; ++j) rotate(matrix, i, j, n);
        
        if (n & 1) for (int i=0; i<m; ++i) rotate(matrix, i, m, n);
    }
private:
    void rotate(vector<vector<int> > & matrix, int i, int j, int n) {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[n-1-j][i];
            matrix[n-1-j][i] = matrix[n-1-i][n-1-j];
            matrix[n-1-i][n-1-j] = matrix[j][n-1-i];
            matrix[j][n-1-i] = tmp;        
    }
};

