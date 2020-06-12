#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

vector<int> adj[MAX];
vector<bool> visited(MAX, 0);

void bfs(int start){
	queue<int> q;
	q.push(start);

	while(!q.empty()){
		int u = q.top();
		cout<< u << ' ';
		q.pop();
		visited[u] = true;

		for(int v: adj[u])
			if(!visited[v]) q.push(v);
	}
	cout<< endl;
}
