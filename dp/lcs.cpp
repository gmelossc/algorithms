#include <bits/stdc++.h>

const int MAX = 1e5 + 1;

int dp[MAX][MAX], rec[MAX][MAX];

void lcs(string &s, string &t){
    int n = s.size();
    int m = t.size();
 
    memset(dp, -0x3f, sizeof(dp));

    dp[0][0] = 0;

    for(int i = 0; i<=n; ++i){
        for(int j = 0; j<=m; ++j){
            if(i + 1 <= n && dp[i + 1][j] < dp[i][j]){
                dp[i+1][j] = dp[i][j];
                rec[i+1][j] = 0;
            }
            if(j + 1 <= m && dp[i][j + 1] < dp[i][j]){
                dp[i][j+1] = dp[i][j];
                rec[i][j+1] = 1;
            }
            if(i + 1 <= n && j + 1 <= m && s[i] == t[j] && dp[i + 1][j + 1] < dp[i][j] + 1){
                dp[i+1][j+1] = dp[i][j] + 1;
                rec[i+1][j+1] = 2; 
            }
        }
    }
}

string rcv(string &s, string &t){
    int n = s.size();
    int m = t.size();
    int cu = dp[n][m] - 1;
    string ans = "";

    for(int i = 0; i<dp[n][m]; ++i) ans += '?';

    while(n || m){
        if(rec[n][m] == 0) n--;
        else if(rec[n][m] == 1) m--;
        else{
            n--;
            m--;
            ans[cu] = t[m];
            cu--;
        }
    }
    return ans;
}
