#include <bits/stdc++.h>
//time complexity: O(m log m)
const int MAX = 1e5;

int parent[MAX], weight[MAX], sz[MAX];

void initSet(int n){
  for(int i = 1; i<=n; ++i) parent[i] = i;
}

int find(int x){ // find a parent of a node
  return parent[x] = (x==parent[x]? x : find(parent[x])); // optimization of else above
}

/*
void join(int x, int y){ makes union of set which x belongs and set which t belongs

    parent[find(x)]=find(y); // turns parent of x into y parent
}
*/

void join(int x, int y){ // optimization of join function above based on weight of most distant descendent of a given value in the set

  x = find(x);
  y = find(y);

  if(x==y) return;

  if(weight[x] > weight[y]) swap(x, y); // if one of parents have less weight(the most distant descendent is "minimized")

  parent[x] = y;
  sz[y] += sz[x];
  if(weight[x] == weight[y]) weight[y]++;
}






struct UnionFind {
  vector<int> uf, w;

  UnionFind(int N) {
    uf.assign(N, 0);
    w.assign(N, 1);

    for(int i=0; i<N; ++i) uf[i] = i;
  }

  int find(int i) {
    return uf[i] == i ? i : uf[i] = find(uf[i]);
  }

  void join(int i, int j) {
    i = find(i);
    j = find(j);
    if(i == j) return;

    if(w[i] > w[j]) {
      w[i] += w[j];
      uf[j] = i;
    } else {
      w[j] += w[i];
      uf[i] = j;
    }
  }
};