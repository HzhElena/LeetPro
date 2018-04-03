/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int n = points.size();
        if (n <= 2) return n;
        
        int maxp = 0;
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            int p = 0;
            int x1 = points[j].x - points[i].x;
            int y1 = points[j].y - points[i].y;
            // duplicate points case
            if ((x1==0) && (y1==0)) continue;
            for (int k=0; k<n; ++k) {
                int x2 = points[k].x - points[i].x;
                int y2 = points[k].y - points[i].y;
                if (x1*y2-x2*y1==0) ++p;
            }
            maxp = max(maxp, p);
        }
        
        for (int i=0; i<n; ++i) {
            int p = 1;
            for (int j=i+1; j<n; ++j) 
                if ((points[j].x==points[i].x) && (points[j].y==points[i].y)) ++p;
            maxp = max(maxp, p);
        }
        
        return maxp;
    }
};