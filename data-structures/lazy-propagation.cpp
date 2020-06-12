#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

int lazy[MAX << 2], st[MAX<< 2], v[MAX];

void push(int node, int i, int j){
	int l = (node << 1);
	int r = (node << 1)|1;

	st[node]+= lazy[node]*(j-i+1);

	if(i != j){
		lazy[l] += lazy[node];
		lazy[r] += lazy[node];
	}
	lazy[node] = 0;
}

void build(int node, int i, int j){
	if(i == j) st[node] = v[i];
	else{
		int l = (node << 1);
		int r = (node << 1)|1;
		int m = (i+j)/2;

		build(l, i, m);
		build(r, m+1, j);

		st[node] = st[r] + st[l];
	}
}

void update(int node, int i, int j, int a, int b, int add){
  int l = 2*node;
  int r = 2*node+1;
  int m = (i+j)/2;

  if(lazy[node]) push(node, i, j);

  if(i > b || a > j) return;
  else if(j <= b && i >= a){
    lazy[node]+= add;
    push(node, i, j);
    return;
  }
  else{
    update(l, i, m, a, b, add);
    update(r, m+1, j, a, b, add);

	st[node] = st[r] + st[l];
  }
}

int query(int node, int i, int j, int a, int b){
  int l = 2*node;
  int r = 2*node+1;
  int m = (i+j)/2;

  if(lazy[node]) push(node, i, j);

  if(i > b || a > j) return 0;
  else if(j <= b && i >= a) return st[node];
  else	return query(r, m+1, j, a, b) + query(l, i, m, a, b);
}
