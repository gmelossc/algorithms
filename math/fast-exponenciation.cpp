#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const ll MOD = 1e9+7;
ll mod(ll x, ll m){ if(x >= 0LL) return x % m; if(-x < m) return m-(-x); return mod(x%m, m);}

ll fexp(int base, ll exp, ll m){
	ll total = 1LL;
	for(;exp ; exp>>=1LL){
		if(exp & 1LL)
			total = mod(((mod(total, m)) * (mod(base, m))), m);
		base= mod((mod(base, m) * mod(base, m)), m);
	}
	return mod(total, m);
}
