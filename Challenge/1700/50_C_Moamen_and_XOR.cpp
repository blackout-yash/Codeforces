// C. Moamen and XOR
// Link - https://codeforces.com/problemset/problem/1557/C



/*--------------------------------------👻 Yash 👻--------------------------------------*/

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define nline "\n"
#define mm (9*1e18)
#define mp make_pair
#define pb push_back
#define int long long
#define mn ((-9)*1e18)
#define lb lower_bound
#define ub upper_bound
#define MOD 1000000007
using namespace chrono;
#define bs binary_search
#define size(x) (x).size()
#define double long double
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
// typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef tree <pair<int, int>, null_type, less <pair <int, int>>, rb_tree_tag, tree_order_statistics_node_update > multipbds;
int modAdd(int a, int b, int m = MOD) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int modSub(int a, int b, int m = MOD) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int modMul(int a, int b, int m = MOD) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int solution(int ans, int m = MOD) {return (ans < 0) ? ans + m : ans;}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " => "; _pprintt(x); cerr << endl;
#else
#define debug(x)
#endif

void _pprintt(int t) {cerr << t;}
void _pprintt(string t) {cerr << t;}
void _pprintt(char t) {cerr << t;}
void _pprintt(double t) {cerr << t;}
void _pprintt(bool t) {cerr << t;}

template <class T, class V> void _pprintt(pair <T, V> p);
template <class T> void _pprintt(vector <T> v);
template <class T> void _pprintt(set <T> v);
template <class T, class V> void _pprintt(map <T, V> v);
template <class T> void _pprintt(multiset <T> v);
template <class T, class V> void _pprintt(pair <T, V> p) {cerr << "{"; _pprintt(p.ff); cerr << ","; _pprintt(p.ss); cerr << "}";}
template <class T> void _pprintt(vector <T> v) {cerr << "[ "; for (T i : v) {_pprintt(i); cerr << " ";} cerr << "]\n";}
template <class T> void _pprintt(set <T> v) {cerr << "[ "; for (T i : v) {_pprintt(i); cerr << " ";} cerr << "]";}
template <class T> void _pprintt(multiset <T> v) {cerr << "[ "; for (T i : v) {_pprintt(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _pprintt(map <T, V> v) {cerr << "[ "; for (auto i : v) {_pprintt(i); cerr << " ";} cerr << "]";}
// void _pprintt(pbds v) {cerr << "[ "; for (auto i : v) {_pprintt(i); cerr << " ";} cerr << "]";}
// void _pprintt(multipbds v) {cerr << "[ "; for (auto i : v) {_pprintt(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------*/
const int n = 1e6;
vector <int> factInv(n), numInv(n), fact(n);

void invNum(int p) {
	numInv[0] = numInv[1] = 1;
	for (int i = 2; i < n; i++)
		numInv[i] = numInv[p % i] * (p - p / i) % p;
}

void invFact(int p) {
	factInv[0] = factInv[1] = 1;

	for (int i = 2; i < n; i++)
		factInv[i] = (numInv[i] * factInv[i - 1]) % p;
}

void _fact(int p) {
	fact[0] = 1;

	for (int i = 1; i < n; i++) {
		fact[i] = (fact[i - 1] * i) % p;
	}
}

int nCr(int n, int r, int p = MOD) {
	return ((fact[n] * factInv[r]) % p * factInv[n - r]) % p;
}

void preCompute(int p = MOD) {
	invNum(p);
	invFact(p);
	_fact(p);
}

int powMod(int a, int b, int m = MOD) {
	a %= m;
	int res = 1;
	while (b > 0) {
		if (b & 1)
			res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}
	return res;
}

void blackout_yash() {
	/*-------__👌Never Give Up👌__-------*/
	/*----__🤭🤭Stop Stalking🤭🤭__----*/


	int n, k;
	cin >> n >> k;

	int cnt = 0;
	fora(j, 0, n) {
		cnt = modAdd(cnt, nCr(n, j, MOD));
		j++;
	}

	vector <int> dp(k + 1);

	dp[0] = 1;
	fora(i, 1, k + 1) {
		if (n & 1) dp[i] = dp[i - 1];
		else dp[i] = powMod(2, (i - 1) * n);

		dp[i] = modAdd(dp[i], modMul(cnt, dp[i - 1]));
	} cout << dp[k] << nline;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	cout << fixed << setprecision(10);
	int _ = 1;
	preCompute();
	cin >> _;
	while (_--) {blackout_yash();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}