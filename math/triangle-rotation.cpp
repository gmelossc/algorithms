#include <bits/stdc++.h>
using namespace std;

/*
    area of triangle = | DET / 2 |

    if DET > 0 -> anti-clockwise rotation
    if DET < 0 -> clockwise rotation
    if DET == 0 -> colinear   
*/

#define X first
#define Y second
#define DET(p1, p2, p3) (p1.X*(p2.Y - p3.Y) - p2.X*(p1.Y - p3.Y) + p3.X*(p1.Y - p2.Y))


int main() {
  pair<int, int> p[3] = { {0, 0}, {1, 0}, {2, 2} };
  cout << DET(p[0], p[1], p[2]) << endl;
}
