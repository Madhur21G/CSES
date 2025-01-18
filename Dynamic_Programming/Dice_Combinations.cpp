#include "bits/stdc++.h"
using namespace std;
#define int long long
const int N = 1e6 + 7;
const int mod = 1e9 + 7;

// dp[i] -> Number of valid ways to get sum i
// Transition -> dp[i] = dp[i - 1] + dp[i - 2] + ... + dp[i - 6];
// Base Case -> n < 0 -> 0 and dp[0] = 1

void solve(){
    int n;
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int x = 1; x <= 6; x++){
            if(x > i) break;
            dp[i] = (dp[i] + dp[i - x]) % mod;
        }
    }

    cout << dp[n] << '\n';
}

signed main(){
    int tc = 1;
    // cin >> tc;
    while(tc--) solve();
    return 0;
}