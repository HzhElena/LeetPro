class Solution {
public:
    int maxProduct(int A[], int n) {
        if (n <= 0) return 0;
        
        long long cur_max = A[0], cur_min = A[0];    
        long long ret = cur_max;
        for (int i=1; i<n; ++i) {
            long long next_max = A[i];
            next_max = max(next_max, max(cur_max * A[i], cur_min * A[i]));
            
            long long next_min = A[i];
            next_min = min(next_min, min(cur_max * A[i], cur_min * A[i]));
            
            cur_max = next_max;
            cur_min = next_min;
            ret = max(ret, cur_max);
        }
        
        return (int)(ret);
    }
};
