/* Author: BitWizz */

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

#define solveT() {int tc; cin >> tc; while (tc--) solve();} // if tc given
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int int64_t
#define nline "\n"
#define inf 1e18
#define pb push_back
#define ppb pop_back
#define set_bits(x) __builtin_popcountll(x)
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update > pbds;
/* find_by_order(K): Returns an iterator to the Kth largest element (counting from zero) */
/* order_of_key (K): Returns the number of items that are strictly smaller than K */

/*----------------------------------------------Debug Template -------------------------------------------------------------*/
#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x<<" "; _print(x); cerr << endl;
#else
#define debug(x);
#endif

void _print(int t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
/*---------------------------------------------------------------------------------------------------------------------------*/
int mod_add (int a, int b, int m) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int mod_mul (int a, int b, int m) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int mod_sub (int a, int b, int m) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int gcd (int a, int b) {if (b > a) {return gcd(b, a);} if (b == 0) {return a;} return gcd(b, a % b);}
int expo (int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
void extendgcd (int a, int b, int*v) {if (b == 0) {v[0] = 1; v[1] = 0; v[2] = a; return ;} extendgcd(b, a % b, v); int x = v[1]; v[1] = v[0] - v[1] * (a / b); v[0] = x; return;} //pass an arry of size1 3
int mminv (int a, int b) {int arr[3]; extendgcd(a, b, arr); return arr[0];} //for non prime b
int mminvprime (int a, int b) {return expo(a, b - 2, b);}
bool revsort(int a, int b) {return a > b;}
int mod_div (int a, int b, int m) {a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m;}  //only for prime m
void swap (int &x, int &y) {int temp = x; x = y; y = temp;}
int combination (int n, int r, int m, int *fact, int *ifact) {int val1 = fact[n]; int val2 = ifact[n - r]; int val3 = ifact[r]; return (((val1 * val2) % m) * val3) % m;}
vector<int> sieve(int n) {int*arr = new int[n + 1](); vector<int> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
int getRandomNumber (int l, int r) {return uniform_int_distribution<int>(l, r)(rng);}
void mhc (int t) {cout << "Case #" << t << ": ";}
/*---------------------------------------------------------------------------------------------------------------------------*/

/*
dp[i] = maximum amount of money we can earn before day i.
*/

void solve() {
	int n; cin >> n;
	map<int, int> cmp;
	vector<int> a(n), b(n), p(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i] >> b[i] >> p[i];
		b[i]++;
		cmp[a[i]];
		cmp[b[i]];
	}

	int cords = 0;
	for (auto &x : cmp)
		x.second = cords++;

	vector<vector<pair<int, int>>> project(cords);
	for (int i = 0; i < n; i++) {
		project[cmp[b[i]]].emplace_back(cmp[a[i]], p[i]);
	}

	vector<int> dp(cords, 0);
	for (int i = 0; i < cords; i++) {
		if (i > 0) dp[i] = dp[i - 1];
		for (auto p : project[i])
			dp[i] = max(dp[i], dp[p.first] + p.second);
	}

	cout << dp[cords - 1] << '\n';
}

signed main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	solve();
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration.count() / 1000 << endl;
#endif
	return 0;
}