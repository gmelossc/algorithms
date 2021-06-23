#include <bits/stdc++.h>
using namespace std;

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

// CALCULATE the number of coprimes of K in range [1, N]

long long coprimes_of_K(int K, long long N) {
    vector<int> primes;
    while(K != 1) {
        primes.push_back(sieve.div[K]);
        K /= sieve.div[K];
    }
    sort(primes.begin(), primes.end());
    primes.resize(unique(primes.begin(), primes.end()) - primes.begin());

    long long answer = N;
    int S = (int) primes.size();
    for(int mask=1; mask < (1 << S); ++mask) {
        int cnt = 0;
        int prod = 1;
        for(int i=0; i<S; ++i) {
            if(mask & (1 << i)) {
                cnt++;
                prod *= primes[i];
            }
        }
        if(cnt & 1) answer -= N / prod;
        else answer += N / prod;
    }
    return answer;
}