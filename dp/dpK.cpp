#include <bits/stdc++.h>

using namespace std;

#define glhf ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
typedef long long ll;
//#define int ll
#define swap(x, y)((x) ^ (y) ? (x)^=(y)^=(x)^=(y) : (x))
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vector<int>> matrix;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(c) c.begin(),c.end()
#define mp make_pair
#define pb push_back
#define ff first
#define tcase int _; cin>> _; for( ; _; --_)
#define ss second
#define endl '\n'
const int MAX = 1e6+1;
const int INF = 0x3f3f3f3f;
const double PI = acos(-1);
const double DEG = 180/PI;
const int MOD = 1e9+7;
int mod(int x, int m){ if(x >= 0) return x % m; if(-x < m) return m-(-x); return mod(x%m, m);}
//std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());


void solve(){
	int n, s; cin >> n >> s;
	vi w, v;

	for(int i = 0; i < n ; ++i){
		int value, weight, k;
		cin >> value >> weight >> k;
		int mx = 0;

		for(int j = 1; j <= k; j <<= 1){
			if(j & k && j * weight <= s) v.pb(j * value), w.pb(j * weight);
			mx = max(mx, j);
		}
		
		v.pb(value * (k - mx + 1)), w.pb(weight * (k - mx + 1));
	}
	

	n = v.size();
	
	int dp[n * s+ 1];
	memset(dp, 0, sizeof(dp));
	int ans = 0;

	for(int i = 0; i < n; ++i)
		for(int j = s; j >= 0; --j)
			if(j + w[i] <= s){
				dp[j + w[i]] = max(dp[j + w[i]], dp[j] + v[i]);
				ans = max(ans, dp[j + w[i]]);
			}

	cout << ans << endl;
}

int32_t main(){
	glhf;
	solve();
	return 0;
}



