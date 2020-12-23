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
