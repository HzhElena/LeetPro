class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<string> ans;
        for (int i=0, n=words.size(); i<n; ) {
            int used = words[i].size(), j = i+1;
            while ((j<n) && (used+words[j].size()+1<=L)) {
                used += words[j].size() + 1;
                ++j;
            }
            int spaces = L - used;
            string line = words[i];
            if  ((j==n)||(i+1==j)) {
                for (int k=i+1; k<j; ++k) line = line + ' ' + words[k];
                line = line + string(spaces, ' ');
            }
            else {
                int sp = spaces / (j-i-1);
                int extra = spaces % (j-i-1);
                for (int k=i+1; k<j; ++k) {
                    line = line + string(sp+1, ' ');
                    if (k-i <= extra) line = line + ' ';
                    line = line + words[k];
                }
            }
            ans.push_back(line);
            i = j;
        }
        return ans;
    }
};

