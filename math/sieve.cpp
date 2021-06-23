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





struct Sieve {
    vector<int> div;
    vector<int> primes;
    Sieve(int N) {
        div = vector<int>(N+1, 1);
        for(int i=1; i<N; ++i) div[i] = i;
        for(long long i=2; i<N; ++i) {
            if(div[i] != i) continue;
            primes.push_back(i);
            for(long long j = i*i; j<N; j += i) {
                div[j] = i;
            }
        }
    }
};
const Sieve sieve(1'000'100);