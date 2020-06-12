#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 1;

int bit[MAX], n;

int sum(int x){
  int s = 0;

  for( ; x>0; x-=(x & -x)) s += bit[x];

  return s;
}

void update(int x, int v){
  for( ; x<=n; x+= (x & -x)) bit[x] += v;
}
