#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

typedef vector<int> vi;
typedef pair<int, int> pii;

bool visited[MAX];

vector<pii> adj[MAX];

vi dfs(int start){
	vi path;
	stack<int> s;
	s.push(start);

	while(!s.empty()){
		int u = s.top();
		s.pop();

		for(pii v: adj[u]){
			if(!visited[v.second]){
				visited[v.second] = 1;
				s.push(v.first);
			}
		}
		path.push_back(u);
	}
	return path;
}
