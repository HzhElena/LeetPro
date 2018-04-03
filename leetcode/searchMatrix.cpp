class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty() || matrix[0].empty()) return false;
        int r = matrix.size(), c = matrix[0].size();
        
        for (int i=r-1, j=0; (i>=0)&&(j<c); ) {
            int delta = matrix[i][j] - target;
            if (delta == 0) return true;
            if (delta > 0) --i; else ++j;
        }
        
        return false;
    }
};

