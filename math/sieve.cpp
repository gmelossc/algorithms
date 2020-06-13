#include <bits/stdc++.h>

using namespace std;

const int MAX = 1e6;

vector<bool> sieve(MAX, true);

void prepros(){
	sieve[0] = sieve[1] = false;

	for(int i = 2; i*i <= MAX; ++i){
		if(sieve[i])
			for(int j = i*i; j<=MAX; j+=i) sieve[j] = false;
	}

	// vi prime;
	// for(int i = 2; i<=MAX; ++i)
		// if(sieve[i]) prime.push_back(i);
	// return prime;
}
