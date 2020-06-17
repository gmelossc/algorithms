#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
const int LOG = 20;

int parent[MAX][LOG];
int depth[MAX];
vector<int> adj[MAX];

void dfs(int start){
	stack<int> s;
	s.push(start);

	while(!s.empty()){
		int u = s.top();
		s.pop();

		for(int v: adj[u]){
			if(depth[v] == -1){
				parent[v][0] = u;
				depth[v] = depth[u] + 1;
				s.push(v);
			}
		}
	}
}

void precompute(){
	memset(parent, -1, sizeof(parent));
	memset(depth, -1, sizeof(depth));
	depth[0] = parent[0][0] = 0;
	dfs(0);

	for(int i = 1; i<LOG; ++i)
		for(int j = 0; j<n; ++j)
			if(parent[j][i-1] != -1) parent[j][i] = parent[parent[j][i-1]][i-1];
}

// remember that the distance between u and v is depth[u] + depth[v] - 2*depth[lca(u, v)]

int lca(int u, int v){
	if(depth[u] < depth[v]) swap(u, v);

	int diff = depth[u] - depth[v];
	for(int i = 0; i< LOG; ++i)
		if((1 << i) & diff) u = parent[u][i];

	if(u == v) return u;

	for(int i = LOG-1; i>=0; --i)
	 	if(parent[u][i] != -1 && parent[u][i] != parent[v][i]){
			u = parent[u][i];
			v = parent[v][i];
		}
		return parent[u][0];
}
