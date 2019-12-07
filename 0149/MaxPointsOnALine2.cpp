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
    int maxPoints(vector<Point>& points) {
        unordered_map<double, int> slope;
        int max_p = 0, same_p = 1, same_v = 1;
        
        for (int i = 0; i < points.size(); i++) {
            for (int j = i+1; j < points.size(); j++) {
                if (points[i].y == points[j].y) {
                    same_v++;
                    if (points[i].x == points[j].x)
                        same_p++;
                } else {
                    slope[(double)(points[i].x - points[j].x) / (points[i].y - points[j].y)]++;
                }
            }
            max_p = max(max_p, same_v);
            
            for (const auto &s : slope) {
                max_p = max(max_p, s.second + same_p);
            }
            
            slope.clear();
            same_p = same_v = 1;
        }

        return max_p;
    }
}; 
