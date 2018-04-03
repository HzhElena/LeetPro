class Solution {
public:
    void setZeroes(vector<vector<int> > &mat) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (mat.empty()||mat[0].empty()) return;
        int r = mat.size(), c = mat[0].size();
        bool firstRowZ = false, firstColZ = false;
        for (int j=0; j<c; ++j) if (mat[0][j] == 0) firstRowZ = true;
        for (int i=0; i<r; ++i) if (mat[i][0] == 0) firstColZ = true;
        
        for (int i=1; i<r; ++i) for (int j=1; j<c; ++j) 
            if (mat[i][j] == 0) {
                mat[i][0] = mat[0][j] = 0;
            }
            
        for (int i=1; i<r; ++i) for (int j=1; j<c; ++j)
            if ((mat[i][0]==0)||(mat[0][j]==0)) mat[i][j] = 0;
        if (firstRowZ) for (int j=0; j<c; ++j) mat[0][j] = 0;
        if (firstColZ) for (int i=0; i<r; ++i) mat[i][0] = 0;
    }
};

