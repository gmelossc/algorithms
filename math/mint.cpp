#include <bits/stdc++.h>
using namespace std;

struct mint {
private:
	const int MOD = 1'000'000'007;
	int mod(long long x) {
		if(x >= 0) return x % MOD;
		if(-x < MOD) return MOD - (-x);
		return mod(x % MOD);
	}
	int n;

public:
	mint() {
		n = 0;
	}

	mint(int _n) {
		n = mod(_n);
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

	mint operator=(const mint &rhs) {
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
	mint u = v * v * v * v * v;

	cout << u << endl;

	return 0;
}