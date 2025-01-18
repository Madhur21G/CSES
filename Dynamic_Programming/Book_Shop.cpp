#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;
// #define int int64_t

// dp[i, x] -> maxm number of pages I can buy from first i books using x money
// Final Ans -> dp[n, x]
// dp[i, x] = max(dp[i - 1, x], hi + dp[i - 1, x - si])

void solve(){
    int n, x;
    cin >> n >> x;
    vector<int> price(n), pages(n);
    for(int &x : price) cin >> x;
    for(int &x : pages) cin >> x;

    vector<vector<int>> dp(n + 1, vector<int> (x + 1, 0));
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i - 1][j];
            int left = j - price[i - 1];
            if(left >= 0){
                dp[i][j] = max(dp[i][j], dp[i - 1][left] + pages[i - 1]);
            }
        }
    }

    cout << dp[n][x] << '\n';
}

signed main(){
    solve();
    return 0;
}