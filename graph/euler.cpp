#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

typedef pair<int, int> pii;

bool mark[MAX];

vector<pii> adj[MAX];

vector<int> path;

void dfs(int u){
	for (auto v: adj[u]){
		if (!mark[v.second])
		{
			mark[v.second] = 1;
			dfs(v.first);
		}
	}

	path.push_back(u);
}
