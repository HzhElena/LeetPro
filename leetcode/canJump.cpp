class Solution {
public:
    bool canJump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        priority_queue<int> pq;
        pq.push(A[0]);
        int last = 0;
        while (!pq.empty()) {
            int R = pq.top();
            pq.pop();
            if (R >= n-1) return true;
            for (int i=last+1; i<=R; ++i) pq.push(i+A[i]);
            last = R;
        }
        return false;
    }
};

