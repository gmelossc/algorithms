#include <bits/stdc++.h>

using namespace std;

typedef vector<int> vi;
const int MAX = 1e6 + 1;

int color[MAX], n, m;
vi adj[MAX];

void coloring(int i){
	color[i] = 0;

	queue<int> q;
	q.push(i);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(int v: adj[u]){
			if(color[v] == -1){
				color[v] = 1 - color[u];
				q.push(v);
			}
		}
	}
}

bool bipartiteCheck(){
	memset(color, -1, sizeof(color));
	for(int i = 1; i<=n; ++i)
		if(color[i] == -1) coloring(i);

	for(int u = 1; u <= n; ++u)
		for(int v: adj[u])
			if(color[v] == color[u]) return false;

	return true;
}

int32_t main(){
	cin >> n >> m;

	for(int i =0 ; i < m; ++i){
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	cout << (bipartiteCheck() ? "B\n" : "NB\n");
	return 0;
}
