#include "temp.cpp"
#include <algorithm>
#include <array>

using namespace ::std;

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