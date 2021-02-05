#include <bits/stdc++.h>
using namespace std;

string lcs(string a, string b) {
    int n = a.size();
    int m = b.size();
    vector<vector<int>> seq(n+1, vector<int>(m+1, 0));
    vector<vector<pair<int,int>>> par(n+1, vector<pair<int,int>>(m+1));

    for(int i=1; i<=n; i++) for(int j=1; j<=m; j++) {
        int mx=0;
        mx = max(mx, seq[i-1][j]);
        mx = max(mx, seq[i][j-1]);
        if(a[i-1] == b[j-1]) mx = max(mx, 1+seq[i-1][j-1]);
        seq[i][j] = mx;
    }
    
    cout << seq[n][m];

    string s = "";
    return s;
}

int main() {
    string a, b;
    cin >> a >> b;
    lcs(a, b);
    return 0;
}
