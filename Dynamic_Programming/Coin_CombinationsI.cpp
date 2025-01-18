#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
#define int int64_t

// dp[i] -> Number of ways to form sum == i with given coins
// Final Ans -> dp[x]
// dp[i] = dp[i - c1] + dp[i - c2] + .. + dp[i - cn]
// Time Complexity = O(nx)

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int &x : c) cin >> x;

    vector<int> dp(x + 1);
    dp[0] = 1;
    for(int i = 1; i <= x; i++){
        dp[i] = 0;
        for(int val : c){
            if(val <= i){
                dp[i] = (dp[i] + dp[i - val]) % mod;
            }
        }
    }

    cout << dp[x] << '\n';
}

signed main(){
    solve();
    return 0;
}