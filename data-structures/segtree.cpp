#include <bits/stdc++.h>

const int MAX = 1e5;
// time complexity: O(nlog n)
//for each node i, we have a node built on a heap structure, so left son is 2*i and right son is 2*i+1
//for each node [i, j] --> left son is [i, (i+j)/2] and right son is [(i+j)/2 +1 , j]
//in this example i'll use seg tree to find the minimum value in a given range [a, b], so each node has the min value in [i, j]
int st[4*MAX], values[MAX];

void build(int node, int i, int j){ // build seg tree at initial state
  if(i == j){ // if node is a leaf
    st[node] = values[i]; // some value, depending on the problem youre solving
    return;
  }
  else{ // otherwise
    int l = 2*node;
    int r = 2*node + 1;
    int m = (i+j)/2;

    build(l, i, m+1);
    build(r, m+1, j);

    //do some stuff on your seg tree
    if(values[st[l]] < values[st[r]]) st[node] = st[l];
    else st[node] = st[r];
  }
}

void update(int node, int i, int j, int pos, int new_value){ // updates a new_value in a given positiion pos and recalculates each node in O(log n)
  if(i == j && j == pos){
    values[i] = new_value;
  }
  else{
    int l = 2*node;
    int r = 2*node+1;
    int m = (i+j)/2;

    if(pos <= m) update(l, i, m, pos, new_value); // if pos is before middle position, we go to left node
    else update(r, m+1, j, pos, new_value);// else we go to a right node

    //do some trivial alteration on st[node] depending on the problem needs
    if(values[st[r]] < values[st[l]]) st[node] = st[r];
    else st[node] = st[l];
  }
}

int query(int node, int i, int j, int a, int b){
  if(i>=a && j <= b) return st[node]; //if [i,j] is subset of [a, b], we already have this value precalculated
  else return -1; // else the both sets are disjoint

  //otherwise, need to calculate the insersection of sets

  int l = 2*node;
  int r = 2*node+1;
  int m = (i+j)/2;

  int lans = (l, i, m, a, b);
  int ras = (r, m+1, j, a, b);

  if(rans == -1) return lans;
  if(lans == -1) return rans;

  if(lans < rans) return lans;
  else return rans;
}
