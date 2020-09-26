#include <bits/stdc++.h>

using namespace std;

int f(int k){
	// ...
}

int ts(int l, int r){
	while(l < r){
		int m1 = l + (r - l)/3;
		int m2 = r - (r - l)/3;

		if(f(m1) > f(m2)) l  = m1;
		else r = m2;
	}
	return r;
}
