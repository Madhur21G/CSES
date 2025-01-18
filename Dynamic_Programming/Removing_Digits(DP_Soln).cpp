#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
#define int int64_t

// dp[i] -> minimum number of steps needed to go from i to 0
// Final Ans -> dp[n]
// dp[n] -> 1 + dp[n - di] minimum over all valid di

void solve(){
    int n;
    cin >> n;

    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for(int i = 0; i <= n; i++){
        for(char ch : to_string(i)){
            dp[i] = min(dp[i], dp[i - (ch - '0')] + 1);
        }
    }

    cout << dp[n] << '\n';
}

signed main(){
    solve();
    return 0;
}