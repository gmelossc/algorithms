#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define tcase int _; cin >> _; while(_--)
const int MAX = 1e6;

int n; // interval size 1 .. n
int m; // m subintervals
pair<int, int> v[MAX];	// cover intervals 

void solve() {
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		v[i] = {a, b};
	}
	sort(v, v+m);
	int ans=0;
	int cover=1;
	int i=0;
	while(i<m) {
		int ncover=0;
		while(i<m && v[i].first <= cover) {
			ncover = max(ncover, v[i].second);
			i++;
		}
		if(ncover > cover) {
			ans++;
			cover = ncover;
			if(cover >= n) break;
		} else {
			ans = -1;
			break;
		}	
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

 	solve();

  	return 0;
}

