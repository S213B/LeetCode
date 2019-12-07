#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
#include <numeric>

using namespace std;
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int gcd(int u, int v) {
        while (v != 0) {
            int r = u % v;
            u = v;
            v = r;
        }
        return u;
    }

#if 0
    static bool point_cmp(const Point &a, const Point &b) {
        return !((a.x == b.x) && (a.y == b.y));
    }
#endif

    int maxPoints(vector<Point>& points) {
        unordered_map<int, set<Point *>> map_x, map_y;
        unordered_map<string, unordered_map<string, set<Point *>>> map;
#if 0
        set<Point, decltype(point_cmp)*> _points(points.begin(), points.end(), point_cmp);
        points.assign(_points.begin(), _points.end());
#endif
        int sz = points.size();
        int max = sz ? 1 : 0;
        //string _k1, _k2;

        for (int i = 0; i < sz; i++) {
            Point pi = points[i];
            //cout << "i:" << pi.x << " " << pi.y << endl;
            for (int j = i+1; j < sz; j++) {
                Point pj = points[j];
                //cout << "j:" << pj.x << " " << pj.y << endl;
                if (pi.x == pj.x) {
                    map_x[pi.x].insert(&points[i]);
                    map_x[pi.x].insert(&points[j]);
                    max = map_x[pi.x].size() > max ? map_x[pi.x].size() : max;
                    //cout << "x only:" << "x1,y1:" << pi.x << ',' << pi.y << " x2,y2:" << pj.x << ',' << pj.y << endl;
                } else if (pi.y == pj.y) {
                    map_y[pi.y].insert(&points[i]);
                    map_y[pj.y].insert(&points[j]);
                    max = map_y[pi.y].size() > max ? map_y[pi.y].size() : max;
                    //cout << "y only:" << "x1,y1:" << pi.x << ',' << pi.y << " x2,y2:" << pj.x << ',' << pj.y << endl;
                } else {
                    int a = pi.y - pj.y;
                    int b1 = pi.x - pj.x;
                    int b2 = pi.x - pj.x;
                    int c = pi.x * pj.y - pj.x * pi.y;

                    //cout << ":" << a << " " << b1 << " " << c << endl;

                    if ((a < 0 && b1 < 0) || (a > 0 && b1 < 0)) {
                        a = -a;
                        b1 = -b1;
                    }
                    if ((c < 0 && b2 < 0) || (c > 0 && b2 < 0)) {
                        c = -c;
                        b2 = -b2;
                    }

                    int g1 = gcd(abs(a), abs(b2));
                    int g2 = gcd(abs(c), abs(b2));

                    string k1 = to_string(a/g1) + ',' + to_string(b1/g1);
                    string k2 = to_string(c/g2) + ',' + (c ? to_string(b2/g2) : "0");
                    //cout << k1 << "   " << k2 << endl;
                    //cout << a << " " << b << " " << c << " " << map[a][b][c].size() << endl;
                    map[k1][k2].insert(&points[i]);
                    map[k1][k2].insert(&points[j]);
#if 0
                    if (map[k1][k2].size() > max) {
                        _k1 = k1;
                        _k2 = k2;
                    }
#endif
                    max = map[k1][k2].size() > max ? map[k1][k2].size() : max;
                }
            }
        }

#if 0
        //cout << _k1 << endl;
        //cout << _k2 << endl;
        for (const auto p : map[_k1][_k2]) {
            cout << p->x << ',' << p->y << endl;
        }
#endif

        return max;
    }
};

//#define TEST3

int main()
{
    Solution s;
#ifdef TEST1
    vector<Point> v = {{1,1}, {2,2}, {3,3}, {4,4}};
#elif defined TEST2
    vector<Point> v = {{0,0}, {-1,-1}, {2,2}};
#elif defined TEST3
    vector<Point> v = {{-240,-657},{-27,-188},{-616,-247},{-264,-311},{-352,-393},{-270,-748},{3,4},{-308,-87},{150,526},{0,-13},{-7,-40},{-3,-10},{-531,-892},{-88,-147},{4,-3},{-873,-555},{-582,-360},{-539,-207},{-118,-206},{970,680},{-231,-47},{352,263},{510,143},{295,480},{-590,-990},{-236,-402},{308,233},{-60,-111},{462,313},{-270,-748},{-352,-393},{-35,-148},{-7,-40},{440,345},{388,290},{270,890},{10,-7},{60,253},{-531,-892},{388,290},{-388,-230},{340,85},{0,-13},{770,473},{0,73},{873,615},{-42,-175},{-6,-8},{49,176},{308,222},{170,27},{-485,-295},{170,27},{510,143},{-18,-156},{-63,-316},{-28,-121},{396,304},{472,774},{-14,-67},{-5,7},{-485,-295},{118,186},{-154,-7},{-7,-40},{-97,-35},{4,-9},{-18,-156},{0,-31},{-9,-124},{-300,-839},{-308,-352},{-425,-176},{-194,-100},{873,615},{413,676},{-90,-202},{220,140},{77,113},{-236,-402},{-9,-124},{63,230},{-255,-118},{472,774},{-56,-229},{90,228},{3,-8},{81,196},{970,680},{485,355},{-354,-598},{-385,-127},{-2,7},{531,872},{-680,-263},{-21,-94},{-118,-206},{616,393},{291,225},{-240,-657},{-5,-4},{1,-2},{485,355},{231,193},{-88,-147},{-291,-165},{-176,-229},{154,153},{-970,-620},{-77,33},{-60,-111},{30,162},{-18,-156},{425,114},{-177,-304},{-21,-94},{-10,9},{-352,-393},{154,153},{-220,-270},{44,-24},{-291,-165},{0,-31},{240,799},{-5,-9},{-70,-283},{-176,-229},{3,8},{-679,-425},{-385,-127},{396,304},{-308,-352},{-595,-234},{42,149},{-220,-270},{385,273},{-308,-87},{-54,-284},{680,201},{-154,-7},{-440,-475},{-531,-892},{-42,-175},{770,473},{118,186},{-385,-127},{154,153},{56,203},{-616,-247}};
#else
    vector<Point> v = {{0,0}, {1,1}, {0,0}};
#endif

    cout << s.maxPoints(v) << endl;

    return 0;
}
