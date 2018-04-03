class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> ans;
        if (matrix.empty() || matrix[0].empty()) return ans;
        int r = matrix.size(), c = matrix[0].size();
        
        vector<vector<bool> > used(r, vector<bool>(c, false));
        int x = 0, y = -1, d = 0;
        for (int i=0, rc=r*c; i<rc; ++i) {
            for (;;) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if ((nx<0)||(nx>=r)||(ny<0)||(ny>=c)|| used[nx][ny]) d = (d + 1) & 3;
                else {
                    x = nx; y = ny; break;
                }
            }
            used[x][y] = true;
            ans.push_back(matrix[x][y]);
        }
        return ans;
    }
private:
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
};
