#include <bits/stdc++.h>
using namespace std;

const int mxN = 501, mxST = mxN*mxN<<4;

int mat[mxN][mxN];
int st[mxST], lazy[mxST];
int n, x, y, x2, y2, v;

void push(int p) {
	for(int i=1; i<=4; i++) {
		st[4*p+i] += lazy[p];
		lazy[4*p+i] += lazy[p];
	}
	lazy[p]=0;
}

void upd(int p, int l, int r, int u, int d) {
	if(l > x2 || r < x || u > y2 || d < y || l > r || u > d) return;
	push(p);
	if(l >= x && r <= x2 && u >= y && d <= y2) {
		lazy[p] = v;
		st[p] += v;
		return;
	}
	int imid=(u+d)/2, jmid=(l+r)/2;
	upd(4*p+1, l, jmid, u, imid);
	upd(4*p+2, l, jmid, imid+1, d);
	upd(4*p+3, jmid+1, r, u, imid);
	upd(4*p+4, jmid+1, r, imid+1, d);
	int mx = 0;
	for(int i=1; i<=4; i++) mx = max(mx, st[4*p+i]);
	st[p] = mx;
}

int qry(int p, int l, int r, int u, int d) {
	if(l > x2 || r < x || u > y2 || d < y || l > r || u > d) return 0;
	push(p);
	if(l >= x && r <= x2 && u >= y && d <= y2) return st[p];
	int mx = 0;
	int imid=(u+d)/2, jmid=(l+r)/2;
	mx = max(mx, qry(4*p+1, l, jmid, u, imid));
	mx = max(mx, qry(4*p+2, l, jmid, imid+1, d));
	mx = max(mx, qry(4*p+3, jmid+1, r, u, imid));
	mx = max(mx, qry(4*p+4, jmid+1, r, imid+1, d));
	return mx;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	memset(lazy, 0, sizeof lazy);
	int n;
	cin >> n;
	for(int i=0; i<n; i++) for(int j=0; j<n; j++) {
		cin >> v;
		x = x2 = j;
		y = y2 = i;
		upd(0, 0, n-1, 0, n-1);
	}
	cout << "update range (x1, y1, x2, y2, +v): " << endl;
	cin >> x >> y >> x2 >> y2;
	upd(0, 0, n-1, 0, n-1);
	cout << qry(0, 0, n-1, 0, n-1) << "\n";
	
	return 0;
}
