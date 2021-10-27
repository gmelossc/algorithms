#include <bits/stdc++.h>
using namespace std;

vector<int> lis(vector<int> arr) {
    int n = arr.size();
    int max_j=0;
    vector<int> ans, seq(n+1, INT_MAX), par(n+1), idx(n+1);
    idx[0] = -1;
    seq[0] = INT_MIN;

    for(int i=0; i<n; i++) {
        int j = lower_bound(seq.begin(), seq.end(), arr[i]) - seq.begin();
        seq[j] = arr[i];
        idx[j] = i;
        par[i] = idx[j-1];
        max_j = max(j, max_j);
    }

    for(int p = idx[max_j]; p != -1; p = par[p]) {
        ans.push_back(arr[p]);
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
