#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
#define int int64_t

// dp[i, x] -> number of valid arrays of size i such that last element is x
// Summation x = 1 to m dp[n, x]
// dp[i, x] = 0 if Ai /= 0 && Ai /= x
// dp[i, x] = x if Ai = 0 || Ai = x <- dp[i - 1, x - 1] + dp[i - 1, x] + dp[i - 1, x + 1]
// Base case -> dp[1, x] = 1 if Ai = 0 || Ai = x and 0 if Ai /= x

bool valid(int x, int m){
    return x >= 1 and x <= m;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int &x : a) cin >> x;

    vector<vector<int>> dp(n + 1, vector<int> (m + 1));\
    for(int i = 1; i <= m; i++){
        if(a[0] == i || a[0] == 0) dp[1][i] = 1;
    }

    for(int i = 2; i <= n; i++){
        for(int k = 1; k <= m; k++){
            if(a[i - 1] != 0 && a[i - 1] != k){
                dp[i][k] = 0;
                continue;
            }

            for(int prev = k - 1; prev <= k + 1; prev++){
                if(!valid(prev, m)) continue;
                dp[i][k] = (dp[i][k] + dp[i - 1][prev]) % mod;
            }
        }
    }
    
    int ans = 0;
    for(int i = 1; i <= m; i++){
        ans = (ans + dp[n][i]) % mod;
    }

    cout << ans << '\n';
}

signed main(){
    solve();
    return 0;
}