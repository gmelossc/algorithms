#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;
typedef vector<int> vi;

vi adj[MAX];
int grau[MAX];
int n; //number of nodes and edges

void readGraph(){
	for(int i = 1; i <= m; ++i){
		int u, v;
		cin>> u>> v;

		grau[v]++;
		adj[u].push_back(v);
	}
}

vi toposort(){
	vi list;

	readGraph();

	for(int i = 1; i<=n; ++i)
		if(grau[i] == 0) list.push_back(i);

	int ini = 0;

	while(ini < list.size()){
		int current = list[ini];
		ini++;

		for(int v: adj[current]){
			grau[v]--;
			if(grau[v] == 0) list.push_back(v);
		}
	}

	// if(list.size() < n) cout<< "Impossible\n";
	// else{
	// 	for(int i: list) cout<< i << ' ';
	// 	cout << '\n';
	// }
	return list;
}
