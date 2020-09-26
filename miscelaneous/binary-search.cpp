#include <bits/stdc++.h>

const int MAX = 1e6;

int bsearch(int l, int r, int x, vector<int> &v){
	// sort(v.begin(), v.end());

	while(l <= r){
		int m = (l+r)/2;

		if(v[m] == x) return m;
		else if(v[m] < x) l = m+1;
		else r = m-1;
	}
	return -1;
}

/*
 * - In Lower/Upper Bound, search is in the interval [l, r)
 * - Input vector should be sorted
 */

// return first position P where v[P] >= x
int lbound(int l, int r, int x, vector<int> &v) {
	int mid;
	while(l < r) {
		mid = (l+r)/2;
		if(x <= v[mid]) r = mid;
		else l = mid+1;
	}
	return r;
}

// return first position P where v[p] > x
int ubound(int l, int r, int x, vector<int> &v) {
	int mid;
	while(l < r) {
		mid = (l+r)/2;
		if(x < v[mid]) r = mid;
		else l = mid+1;
	}
	return r;
}
