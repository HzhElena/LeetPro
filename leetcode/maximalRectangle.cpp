class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (matrix.empty() || matrix[0].empty()) return 0;
        int n = matrix[0].size();
        vector<int> left(n), right(n), A(n, 0);
        
        int maxArea = 0;
        for (int r=0; r<matrix.size(); ++r) {
            for (int j=0; j<n; ++j) if (matrix[r][j] == '1') ++A[j]; else A[j] = 0;
            
            vector<int> stk;
            for (int j=0; j<n; ++j) {
                left[j] = j;
                while (!stk.empty() && (A[stk.back()] >= A[j])) {
                    left[j] = left[stk.back()];
                    stk.pop_back();
                }
                stk.push_back(j);
            }
            
            stk.clear();
            for (int j=n-1; j>=0; --j) {
                right[j] = j;
                while (!stk.empty() && (A[stk.back()] >= A[j])) {
                    right[j] = right[stk.back()];
                    stk.pop_back();
                }
                stk.push_back(j);
            }
            
            for (int j=0; j<n; ++j) {
                int area = (right[j] - left[j] + 1) * A[j];
                maxArea = max(maxArea, area);
            }
        }
        
        return maxArea;
    }
};

