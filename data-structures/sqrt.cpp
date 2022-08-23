#include <bits/stdc++.h>
using namespace std;

const int MAX = 1'000'001;

int N;
int A[MAX];

int SQRT, SIZE;
long long sq[1001];

void build() {
    SQRT = (int) sqrt(N);
    SIZE = (N + SQRT - 1) / SQRT;
    for(int i=0; i<SIZE; ++i) {
        for(int j=0; j<SQRT and i*SQRT + j < N; ++j) {
            sq[i] += A[i*SQRT + j]; 
        }
    }
}

void update(int p, int x) {
    sq[(p/SQRT) + (p%SQRT)] += x - A[p];
    A[p] = x;
}

long long query(int a, int b) {
    int pb = (b / SQRT);
    int pa = min(pb, (a + SQRT - 1) / SQRT);

    long long sum = 0;

    for(; a < SQRT*pa; ++a) sum += A[a];
    for(; pa < pb; pa++, a += SQRT) sum += sq[pa];
    for(; a <= b; a++) sum += A[a]; 

    return sum;
}

int main() {

    cin >> N;
    for(int i=0; i<N; ++i) cin >> A[i];

    build();

    int M;
    cin >> M;

    while(M--) {
        int t;
        cin >> t;

        if(t == 1) {
            int p, x;
            cin >> p >> x;
            update(p, x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << query(a, b) << endl;
        }
    }

    return 0;
}