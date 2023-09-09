#include<bits/stdc++.h>
using namespace std;
using namespace chrono;
typedef long long ll;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

void solve() {
	ll n;
	cin >> n;
	ll k = (n * (n + 1)) / 2;
	ll sum = 0;
	vector<ll>a(n);
	for (int i  = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	cout << k - sum << "\n";
}

int main() {
	fastio();
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	auto start1 = high_resolution_clock::now();
	int tc = 1;
	// cin >> tc;
	while (tc--) {
		solve();
	}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration.count() / 1000 << endl;
#endif
	return 0;
}