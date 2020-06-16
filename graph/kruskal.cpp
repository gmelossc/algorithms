#include <bits/stdc++.h>

const int MAX = 1e6;
typedef vector<int> vi;

int parent[MAX], weight[MAX], sz[MAX];

struct edge{
	int x, int y, int d;
} e[MAX];

bool compare(edge a, edge b){
	return a.d < b.d;
}

void initSet(int n){
  for(int i = 1; i<=n; ++i) {
	  parent[i] = i;
	  sz[i] = 1;
	  w[i] = 0;
  }
}

int find(int x){
  return parent[x] = (x==parent[x]? x : find(parent[x]));
}

void join(int x, int y){

  x = find(x);
  y = find(y);

  if(x==y) return;

  if(weight[x] < weight[y]) swap(x, y);

  parent[x] = y;
  sz[y] += sz[x];
  if(weight[x] == weight[y]) weight[y]++;
}

int getMST(int m){
	int ans = 0;
	sort(e+1, e+m+1, comp);

	for(int i = 1; i<=m; ++i){
		if(find(e[i].x) != find(e[i].y)){
			join(e[i].x, e[i].y);
			ans += e[i].d;
		}
	}
	return ans;
}
