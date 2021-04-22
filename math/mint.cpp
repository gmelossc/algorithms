#include <bits/stdc++.h>
using namespace std;


struct mint {
private:
	const static int MOD = 1'000'000'007; // IF CHANGED, USE phi FUNCTION TO CALCULATE PHI
	const static int PHI = MOD-1; // THIS IS TRUE ONLY FOR PRIME MOD
	int mod(long long x) {
		if(x >= 0) return x % MOD;
		if(-x < MOD) return MOD - (-x);
		return mod(x % MOD);
	}
	mint pwr(mint a, int b) {
		mint p = 1;
		for(; b; b >>= 1) {
			if(b&1) p *= a;
			a *= a;
		}
		return p;
	}
	mint inv(mint x) {
		return pwr(x, PHI - 1);
	}
	int n;

public:
	mint() {
		n = 0;
	}

	mint(long long _n) {
		n = mod(_n);
	}

	static int phi() {
		int m = MOD;
		int ans = m;
		for(int i=2; m > 1;) {
			if(m % i == 0) {
				ans -= ans/i;
				while(m % i == 0) m /= i;
			}
			i++;
			if(i*i > m) {
				i = m;
			}
		}
		return ans;
	}

	mint operator+=(const mint &rhs) {
		n = mod(n + rhs.n);
		return *this;
	}

	mint operator+(mint rhs) {
		return rhs += *this;
	}

	mint operator-=(const mint &rhs) {
		n = mod(n - rhs.n + MOD);
		return *this;
	}

	mint operator-(mint rhs) {
		return *this -= rhs;
	}

	mint operator*=(const mint &rhs) {
		n = mod(n * 1ll * rhs.n);
		return *this;
	}

	mint operator*(mint rhs) {
		return rhs *= *this;
	}

	mint operator++(int a) {
		mint res = *this;
		*this += 1;
		return res;
	}

	mint operator--(int a) {
		mint res = *this;
		*this -= 1;
		return res;
	}

	mint operator/=(const mint &rhs) {
		mint div = *this * inv(rhs);
		n = div.n;
		return div;
	}

	mint operator/(mint rhs) {
		mint div = *this;
		return div /= rhs; 
	}

	mint operator=(const mint rhs) {
		n = rhs.n;
		return *this;
	}

	friend ostream& operator<<(ostream& os, const mint& obj) {
	      return os << obj.n;
	}

	friend istream& operator>>(istream& is, mint& obj) {
		return is >> obj.n;
	}
};


int main(int argc, char const *argv[])
{
	mint v;
	cin >> v;
	mint u = v * (v + 1) / 2;

	cout << u << endl;

	return 0;
}