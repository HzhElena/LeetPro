class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!s || !p) return s == p;
        while (*p!='*') {
            if (!*s) return *s==*p;
            if ((*s==*p)||(*p=='?')) {++s; ++p;} else return false;
        }
        int ls = strlen(s), lp = strlen(p);
        while (p[lp-1]!='*') {
            if (ls==0) return false;
            if ((s[ls-1]==p[lp-1])||(p[lp-1]=='?')) {--ls; --lp;} else return false;
        }
        if (lp==1) return true;
        
        char *ns = new char[ls+1];
        strncpy(ns, s, ls); ns[ls] = 0;

        return greedy(ns, p, lp);
    }
private:
    const char *afterMatch(const char *s, const char*p, int lp) {
        if (lp==0) return s;
        vector<int> F(lp);
        
        int k = -1;
        F[0] = -1;
        for (int i=1; i<lp; ++i) {
            while ((k!=-1) && (p[i]!=p[k+1]) && (p[k+1]!='?')) k = F[k];
            if ((p[i]==p[k+1]) || (p[k+1] == '?')) ++k;
            F[i] = k;
        }
        
        k = -1;
        while (*s) {
            while ((k!=-1) && (*s!=p[k+1]) && (p[k+1]!='?')) k = F[k];
            if ((*s==p[k+1]) || (p[k+1] == '?')) ++k;
            if (k==lp-1) return s+1;
            ++s;
        }
        
        return NULL;
    }
    
    bool greedy(const char *s, const char *p, int m) {
        int i = 1;
        while ((i<m)&&(p[i]!='*')) ++i;
        if (i == m) return true;
        s = afterMatch(s, p+1, i-1);
        
        if (!s) return false;
        return greedy(s, p+i, m-i);
    }
};

