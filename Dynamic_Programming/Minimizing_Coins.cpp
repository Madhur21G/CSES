#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
#define int int64_t

// dp[i] -> minimum number of coins with sum i
// Final Ans -> dp[x]

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> c(n);
    for(int &x : c) cin >> x;

    vector<int> dp(x + 1, 1e9);
    dp[0] = 0;
    for(int i = 1; i <= x; i++){
        for(int j = 0; j < n; j++){
            if(i - c[j] >= 0){
                dp[i] = min(dp[i], dp[i - c[j]] + 1);
            }
        }
    }
    cout << (dp[x] == 1e9 ? -1 : dp[x]) << '\n';
}

signed main(){
    solve();
    return 0;
}