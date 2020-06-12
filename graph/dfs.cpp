#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

vector<int> adj[MAX];
vector<bool> visited(MAX, 0);
vector<int> depth(MAX, 0);

void dfs(int start){
	stack<int> s;
	s.push(start);

	while(!s.empty()){
		int u = s.top();
		s.pop();
		visited[u] = true;

		for(int v: adj[u]){
			if(!visited[v]){
				depth[v] = depth[u] + 1;
				s.push(v);
			}
		}
	}
}
