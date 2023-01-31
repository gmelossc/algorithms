#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <stack>
#include <vector>
#include <set>
#define fast_input ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace ::std;

#define T int
struct Point {
    T x, y;
    Point() : x(0), y(0) {}
    Point(const T&x, const T&y) : x(x), y(y) {} 

    void swap(Point& o) { std::swap(x, o.x); std::swap(y, o.y); }
    Point& operator = (const Point& other) { x = other.x; y = other.y; return *this; }    
    Point operator - (const Point& other) { x -= other.x; y -= other.y; return Point(x, y); }
    Point operator + (const Point& other) { x += other.x; y += other.y; return Point(x, y); }
    // Point operator > (const Point& a, Point& b) {}
};

Point build(const T& x, const T& y) { return Point(x, y); }
Point add(Point a, Point b) { return build(a.x+b.x, a.y+a.y); }
Point sub(Point a, Point b) { return build(a.x-b.x, a.y-b.y); }
Point mult(Point a, T s) { return build(a.x*s, a.y*s); }
Point div(Point a, T s) { return build(a.x/s, a.y/s); }
T dot(Point a, Point b) { return a.x*b.x  + a.y*b.y; }

// if positive, b points to opposite of vector direction a
// if negative, b points to vector direction a
// if equals 0, b is collinear with a
// cross is anti-symmetric so, a^b = -b^a
T cross(Point a, Point b) { return a.x*b.y - a.y*b.x; }
double anglePoint(Point a) { return atan2(a.y, a.x); }
double angleBetweenPoints(Point a, Point b) { return atan2(cross(a, b), dot(a, b)); }
double angleBetweenPointsToOrigin(Point a, Point b, Point org) {
    return angleBetweenPoints(a-org, b-org);
}

// counterclockwise rotation
Point rotate(Point p, double anglesin, double anglecos) {
    return build(anglecos*p.x - anglesin*p.y,
    anglesin*p.x + anglecos*p.y);
}
Point rotate(Point p, double angle) {
    return rotate(p, sin(angle), cos(angle));
}
T norm(Point a) {
    return sqrt(dot(a, a));
}
T dist(Point a, Point b) {
    return norm(a-b);
}

#define pt Point

int orientation (pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1;
    if (v > 0) return +1;
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);

}

bool ccw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);

}

bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convexHull (vector<pt>& pts, bool include_collinear=false) {
    pt p0 = *min_element(pts.begin(), pts.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });

    sort(pts.begin(), pts.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o==0) {
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
            < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        }
        return o < 0;
    });

    if (include_collinear) {
        int i = (int) pts.size()-1;
        while (i >= 0 && collinear(p0, pts[i], pts.back())) i--;
        reverse(pts.begin()+1, pts.end());
    }

    vector<pt> st;
    for (int i=0; i < (int)pts.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), pts[i], include_collinear)) {
            st.pop_back();
        }
        st.push_back(pts[i]);
    }

    pts=st;
}

void solve() {
}

int main() {
    fast_input;
    while (1) {
        int n;
        cin >> n;
        if (n == 0) break;
        set<pair<int, int>> points;

        for (int i=0; i<n; i++) {
            pair<int, int> point;
            cin >> point.first >> point.second;
            points.insert(point);           
        }

        vector<pt> pts;
        for (auto p: points) pts.push_back(build(p.first, p.second));

        convexHull(pts);

        int s = pts.size();
        cout << pts.size() << endl;


        if (s >= 3 && orientation(pts[0], pts[1], pts[2]) < 0) {
            reverse(pts.begin(), pts.end());
        }

        for (pt p: pts) {
            cout << p.x << " " << p.y << endl;
        }
    }
    return 0;
}