#include <bits/stdc++.h>
using namespace std;

vector<int> factors(long long n) {
    vector<int> f;
    for(int d=2; n>1; ) {
        while(n%d == 0) {
            f.push_back(d);
            n /= d;
        }
        d++;
        if(d * d > n) d = n;
    }
    return f;
}




/* 
	Sieve based solution - FASTER FOR MULTIPLE VALUES 
 	
 	As there are approximately X / ln(X) prime number less then X
 	and for checking if a number is prime we have to check only sqrt(X) values

 	therefore, in the worst case, we check sqrt(X) / ln(sqrt(X)) primes;

 	X = 1'000'000    				-> check = 145
 	X = 1'000'000'000  				-> check = 3'052
 	X = 1'000'000'000'000			-> check = 72'383
 	X = 1'000'000'000'000'000    	-> check = 1'831'147
*/

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


int cnt_factors(long long n) {
    int cnt = 0;
    for(int p : sieve.primes) {
        if(1ll*p*p > n) break;
        while(n % p == 0) {
            cnt++;
            n /= p;
        }
    }
    if(n > 1) cnt++;
    return cnt;
}

vector<int> get_factors(long long n) {
    vector<int> f;
    for(int p : sieve.primes) {
        if(1ll*p*p > n) break;
        while(n % p == 0) {
            f.push_back(p);
            n /= p;
        }
    }
    if(n > 1) {
        f.push_back(n);
    }
    return f;
}