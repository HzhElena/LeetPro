class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int lo=-1, hi = n;
        while (lo+1<hi) {
            int mid = (lo+hi)/2;
            if (A[mid]<target) lo = mid; else hi = mid;
        }
        int start = lo + 1;
        if ((start>=n)||(A[start]!=target)) start = -1;
        
        lo = -1, hi = n;
        while (lo+1<hi) {
            int mid = (lo+hi)/2;
            if (A[mid]<=target) lo = mid; else hi = mid;
        }
        int end = lo;
        if (start==-1) end = -1;
        
        vector<int> ans;
        ans.push_back(start);
        ans.push_back(end);
        return ans;
    }
};

