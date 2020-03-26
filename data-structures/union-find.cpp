#include <bits/stdc++.h>
//time complexity: O
const int MAX = 1e5;

int parent[MAX], weight[MAX];

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

  if(weight[x] < weight[y]) parent[x] = y; // if one of parents have less weight(the most distant descendent is "minimized")
  else if(weight[x] > weight[y]) parent[y] = x;
  else{
    parent[x] = y;
    weight[y]++;
  }
}
