#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e3+1;

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

struct BIT_2D {
	int N, M;
	vector<vector<int>> bit;

	BIT_2D(int n, int m) {
		N = n+1;
		M = m+1;
		bit.assign(N, vector<int>(M, 0));
	}

	void update(int i, int j, int value) {
		for(int x = i; x < N; x += x&-x) {
			for(int y = j; y<M; y += y&-y) {
				bit[x][y] += value;
			}
		}
	}

	int query(int i, int j) {
		int ans = 0;
		for(int x = i; x; x -= x&-x) {
			for(int y = j; y; y -= y&-y) {
				ans += bit[x][y];
			}		
		}
		return ans;
	}

	int upper_bound(int value) {
		// to be implemented
	}

	int lower_bound(int value) {
		// to be implemented
	}
};

int main(int argc, char const *argv[])
{
	BIT_2D b(10, 10);

	b.update(1, 1, 1);
	b.update(1, 5, -1);
	b.update(5, 1, -1);
	b.update(5, 5, 1);

	b.update(4, 4, 1);
	b.update(4, 9, -1);
	b.update(9, 4, -1);
	b.update(9, 9, 1);

	for(int i=1; i<=10; i++) {
		for(int j=1; j<=10; j++) {
			cout << b.query(i, j);
		}
		cout << endl;
	}

	return 0;
}