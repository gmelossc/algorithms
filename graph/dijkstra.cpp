#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
const int INF = 0x3f3f3f3f;

typedef pair<int, int> pii;

vector<pii> adj[MAX];
vector<bool> visited(MAX, false);
vector<int> weight(MAX, INF);
int n;

int dijkstra(int start){
	priority_queue<pii, vector<pii>, greater<pii>> q;
	weight[start] = 0;
	q.push({0, start});

	while(!q.empty()){
		pii current = q.top();
		q.pop();
		int pos = current.s;
		if(!visited[pos]){
			visited[pos] = true;
			for(pii i: adj[pos]){
				int p = i.f;
				int v = i.s;

				if(weight[v] > weight[pos] + p){
					weight[v] = weight[pos] + p;
					q.push({weight[v], v});
				}
			}
		}
	}
	return weight[n];
}
