#include <bits/stdc++.h>

using namespace std;

int mod(int x, int m){
	if(x >= 0) return x % m;
	if(-x < m) return m - (-x);
	return mod(x%m, m);
}

int gcd (int a, int b){
	while(b){
		a = mod(a, b);
		swap(a, b);
	}
	return a;
}
