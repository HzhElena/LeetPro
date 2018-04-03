class Solution {
public:
    int jump(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (n == 1) return 0;
        set<int> q;
        q.insert(A[0]);
        int last = 0, jump = 1;
        while (!q.empty()) {
            int next = *(q.rbegin());
            q.erase(next);
            if (next >= n-1) return jump;
            ++jump;
            for (int i=last+1; i<=next; ++i) q.insert(A[i] + i);
			last = next;
        }
        return -1;
    }
};
