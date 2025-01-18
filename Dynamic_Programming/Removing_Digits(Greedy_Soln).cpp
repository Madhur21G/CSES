#include "bits/stdc++.h"
using namespace std;
const int mod = 1e9 + 7;

void solve(){
    int n;
    cin >> n;

    int cnt = 0;
    while(n > 0){
        string s = to_string(n);
        char maxi = '0';
        for(int i = 0; i < s.size(); i++){
            maxi = max(maxi, s[i]);
        }
        cnt++;
        n -= (maxi - '0');
    }

    cout << cnt << '\n';
}

signed main(){
    solve();
    return 0;
}

/*
Proof By - DebAbhiram Manik Bhaiya

Let's prove the following using induction:

P(n): if ans[10n] = p, then ans[10n], ans[10n + 1], ...., ans[10n + 9] are of the form p, p, p, ....., p, (p + 1), (p + 1), ......, (p + 1)

i.e., some p's followed by some (p + 1)'s such that there is at least one p, and at least one (p + 1)

Moreover, if n > 0, then ans[10n] >= ans[10n - 1]

P(0) is true.

Let P(x) be true, i.e., 

ans[10x], ans[10x + 1], ......, ans[10x + 9]
is of the form:
p, p, p, ......, p, (p + 1), (p + 1), ......, (p + 1)

Then let's prove P(x + 1) holds.

ans[10(x + 1)] = 1 + min(ans[10(x + 1) - d]) for all d in 10(x + 1).

This means that ans[10(x + 1)] is at least p + 1. Let's call this q (so ans[10(x + 1)] = q >= p + 1).

(10(x + 1) + 1) has the same digits as 10(x + 1) except for the last one. If we choose the last digit, then we get the value q + 1 for ans[10(x + 1) + 1]. If we choose some other digit, then we get a value >= q (otherwise, we should have got ans[10(x + 1)] < q).

The same argument holds for ans[10(x + 1) + 2], ....., ans[10(x + 1) + 8].

For 10(x + 1) + 9, the best answer we can get is (q + 1) by choosing the last digit 9, since all other choices will give value at least (q + 1).

So, we have proved P(n) for all n >= 0.

Using the results of P(n), it is easy to see (and prove) that Q(m) holds for all m > 0, where

Q(m): ans[m] >= ans[m - 1] 

So, when we have multiple digits to choose from while calculating ans, it is always optimal to choose the largest digit.
*/