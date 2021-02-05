#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> &v) {
    int n = v.size();
    vector<int> dp(n);
    for(int i=0; i<n; i++) dp[i] = v[i] + max(dp[i-1], 0);
    return *max_element(dp.begin(), dp.end());
}

int kadane2d(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> pref(n, vector<int>(m));
    int ans = -1e9;
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            for(int k=0; k<m; k++) 
                if(i == j) pref[j][k] = mat[j][k];
                else pref[j][k] = pref[j-1][k] + mat[j][k];

            ans = max(ans, kadane(pref[j]));
        }
    }
}