#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e2 + 1;
const int INF = 0x3f3f3f3f;

typedef vector<int> vi;
typedef vector<vi> matrix;

matrix dist(MAX, vi(MAX));

void preprocessing(int n){
	for(int i = 1; i<=n; ++i)
		for(int j = 1; j<=n; ++j) dist[i][j] = (i == j? 0: INF);
}

void fw(int n){
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
