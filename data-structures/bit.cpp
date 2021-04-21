#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6 + 1;

int bit[MAX], n;

int sum(int x){
  int s = 0;

  for( ; x>0; x-=(x & -x)) s += bit[x];

  return s;
}

void update(int x, int v){
  for( ; x<=n; x+= (x & -x)) bit[x] += v;
}


struct BIT {
	int N;
	vector<int> bit;

	BIT(int n) {
		N = n+1;
		bit.assign(N, 0);
	}

	void update(int i, int value) {
		for(; i<N; i += i&-i) {
			bit[i] += value;
		}
	}

	int query(int i) {
		int ans = 0;
		for(; i; i -= i&-i) {
			ans += bit[i];
		}
		return ans;
	}

	int upper_bound(int value) {
		int LOG_N = 1;
		while((2 << LOG_N) < N) LOG_N++;
		int ans = 0;
		int sum = 0;
		for(; LOG_N >= 0; LOG_N--) {
			if(ans + (1 << LOG_N) < N and sum + bit[ans + (1 << LOG_N)] <= value) {
				sum += bit[ans + (1 << LOG_N)];
				ans += (1 << LOG_N);
			}
		}
		return ans;
	}

	int lower_bound(int value) {
		int LOG_N = 1;
		while((2 << LOG_N) < N) LOG_N++;
		int ans = 0;
		int sum = 0;
		for(; LOG_N >= 0; LOG_N--) {
			if(ans + (1 << LOG_N) < N and sum + bit[ans + (1 << LOG_N)] < value) {
				sum += bit[ans + (1 << LOG_N)];
				ans += (1 << LOG_N);
			}
		}
		return ans+1;
	}
};

int main(int argc, char const *argv[])
{
	BIT b(10);

	b.update(3, 1);
	b.update(1, 1);
	b.update(5, 1);
	b.update(8, 1);
	b.update(10, 1);

	cout << b.query(7) << " " << b.lower_bound(3) << " " << b.upper_bound(4);

	return 0;
}