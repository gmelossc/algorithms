#include <bits/stdc++.h>
using namespace std;


struct StringHash {
    int P;
    int M;
    int N;
    vector<int> pref_hash;
    vector<int> pwr;

    StringHash(){};

    StringHash(string &s, int p = 31, int m = 1'000'000'007) {
        this->P = p;
        this->M = m;

        this->N = (int) s.size();
        pref_hash.assign(N+1, 0);
        pwr.assign(N+1, 1);

        for(int i=0; i<N; ++i) {
            pwr[i+1] = (1ll * pwr[i] * p) % m;
            pref_hash[i+1] = (pref_hash[i] + (1ll * pwr[i] * s[i])) % m;
        }
    }

    int rangeHash(int i, int j) {
        return (1ll * pwr[this->N - i] * (pref_hash[j+1] + this->M - pref_hash[i])) % this->M;
    }
};



// int main() {
//     string s = "teste";
//     StringHash hash(s);
//     cout << hash.rangeHash(1, 1) << " " << hash.rangeHash(3, 4) << endl;
// }