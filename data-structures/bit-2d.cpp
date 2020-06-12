#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6+1;

int bit[MAX][MAX], n;

int sum(int x, int y){
	int s = 0;

	for(int i = x; i>0; i -= i & -i)
		for(int j = y; j>0; j -= j & -j)
			s += bit[i][j];

	return s;
}

void update(int x, int y, int v){
	for(int i = x; i < n; i += i & -i)
		for(int j = y; i < n; j += j & -j)
			bit[i][j] += v;
}
