class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > mat(n, vector<int>(n, 0));
        
        int r=0, c=-1, k=0;
        for (int i=0, nn=n*n; i<nn; ++i) {
            for (;;) {
                int x = r + dx[k];
                int y = c + dy[k];
                if ((0<=x)&&(x<n)&&(0<=y)&&(y<n)&&(mat[x][y]==0)) {
                    r = x; c = y; break;
                }
                k = (k+1) & 3;
            }
            mat[r][c] = i+1;
        }
        return mat;
    }
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
};

