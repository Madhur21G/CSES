#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
#define int int64_t

// dp[i, j] -> number of valid paths from [i, j] to [n, n]
// Final Ans -> dp[1, 1]
// dp[i, j] -> dp[i + 1, j] + dp[i, j + 1];
// dp[n, n] -> 1

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> dp(n, vector<int> (n, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        string row;
        cin >> row;
        for(int j = 0; j < n; j++){
            if(row[j] == '.'){
                if(i > 0) dp[i][j] = (dp[i][j] + dp[i - 1][j]) % mod;
                if(j > 0) dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
            }
            else dp[i][j] = 0;
        }
    }
    
    cout << dp[n - 1][n - 1] << '\n';
}

signed main(){
    solve();
    return 0;
}