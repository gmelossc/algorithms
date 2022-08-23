#include <bits/stdc++.h>
using namespace std;

struct RMQ {
    vector<vector<int>> arr;
    vector<int> l;

    RMQ(const vector<int> &_arr) {
        int n = (int)_arr.size();
        l.assign(n+1, 0);
        for(int i=2; i<=n; ++i) l[i] = 1 + l[i>>1];
        arr.assign(l[n]+1, vector<int>(n));
        arr[0] = _arr;
        for(int k=1; k<=l[n]; ++k) {
            for(int i=0; i + (1 << k) <= n; ++i) {
                arr[k][i] = min(arr[k-1][i], arr[k-1][i + (1 << (k-1))]);
            }
        }
    }

    int rmq(int i, int j) {
        int k = l[j-i+1];
        return min(arr[k][i], arr[k][j-(1<<k)+1]);
    }
};

int main() {

    vector<int> arr{1,2,1,2,3,4,2,1};
    RMQ m(arr);

    cout << m.rmq(5, 7) << endl;

    return 0;
}