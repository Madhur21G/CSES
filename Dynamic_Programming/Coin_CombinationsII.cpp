#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;

// dp[i, x] -> number of valid ways to make x using c1, c2, ... , ci
// Final Ans -> dp[n, x]
// dp[i, x] = dp[i - 1, x] + dp[i, x - ci] (Transition)
// Base Case: dp[i, 0] = 1

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int &x : c) cin >> x;

    vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));
    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i - 1][j];
            int left = j - c[i - 1];
            if(left >= 0){
                dp[i][j] = (dp[i][j] + dp[i][left]) % mod;
            }
        }
    }

    cout << dp[n][x] << '\n';
}

signed main(){
    solve();
    return 0;
}