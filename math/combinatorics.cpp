#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int MAX = 1e3;
const int MOD = 1e9+7;

int fact[MAX], inv[MAX];

int pwr(int a, int b) {
  int p = 1;
  for(; b; b >>= 1) {
    if(b&1) p = p*a%MOD;
    a = a*a%MOD;
  }
  return p;
}

void init() {
  fact[0] = 1;
  for(int i=1; i<MAX; i++) fact[i] = i * fact[i-1] % MOD;
  inv[MAX-1] = pwr(fact[MAX-1], MOD-2);
  for(int i=MAX-2; i>=0; i--) inv[i] = (i+1) * inv[i+1] % MOD;
}

int comb(int n, int r) {
  if(n < r) return 0;
  return fact[n] * inv[n-r] % MOD;
}

int ncr(int n, int r) {
  if(n < r) return 0;
  return comb(n, r) * inv[r] % MOD;
}

int32_t main() {

  init();
  int n, r;
  cin >> n >> r;
  cout << ncr(n, r) << endl;

  return 0;
}
