#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MOD = 1e9+7;
int mod(int x, int m){ if(x >= 0) return x % m; if(-x < m) return m-(-x); return mod(x%m, m);}

ll fexp(int base, ll exp, int m){
	ll total = 1;
	while(exp > 0){
		if(exp % 2 == 1){
			total = mod(((mod(total, m)) * (mod(base, m))), m);
			exp--;
		}
		base= mod((mod(base, m) * mod(base, m)), m);
		exp /= 2;
	}
	return mod(total, m);
}
