#include <bits/stdc++.h>

const int MAX = 1e6;

int bsearch(int l, int r, int x, vector<int> &v){
	sort(v.begin(), v.end());

	while(l <= r){
		int m = (l+r)/2;

		if(v[m] == x) return m;
		else if(v[m] < x) l = m+1;
		else r = m-1;
	}
	return -1;
}
