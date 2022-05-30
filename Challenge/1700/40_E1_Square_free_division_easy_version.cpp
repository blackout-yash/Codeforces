// E1. Square-free division (easy version)
// Link - https://codeforces.com/contest/1497/problem/E1



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
#define MOD 1000000007
using namespace chrono;
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

const int MAXN = 1e7 + 1;
int spf[MAXN];

void sieve() {
	spf[1] = 1;
	for (int i = 2; i < MAXN; i++)
		spf[i] = i;

	for (int i = 4; i < MAXN; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < MAXN; i++) {
		if (spf[i] == i) {
			for (int j = i * i; j < MAXN; j += i)
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

vector <int> getFactorization(int x) {
	vector<int> ret;
	while (x != 1) {
		ret.push_back(spf[x]);
		x = x / spf[x];
	} return ret;
}

void blackout_yash() {
	/*-------__👌Never Give Up👌__-------*/
	/*----__🤭🤭Stop Stalking🤭🤭__----*/


	int n, k;
	cin >> n >> k;

	vector <int> arr(n);
	for (auto &xx : arr) cin >> xx;

	int ans = 1, cnt = 0;
	map <int, int> m, check;
	fora(i, 0, n) {
		if (floor(sqrt(arr[i])) == ceil(sqrt(arr[i]))) cnt++;

		if (cnt == 2 || m.count(arr[i]) || check.count(arr[i])) {
			ans++; cnt = 0;
			i--; m.clear();
			check.clear();
		} else {
			vector <int> temp = getFactorization(arr[i]);
			map <int, int> store;
			for (auto x : temp) store[x]++;

			int num = 1;
			for (auto x : store) {
				if (x.ss & 1) num *= x.ff;
			}

			int flag = 1;
			if (num > 1) {
				if (m.count(num)) {
					ans++; cnt = 0;
					i--; m.clear();
					check.clear();
					flag = 0;
				} else check[num] = 1;
			} if (flag) m[arr[i]]++;
		}
	} cout << ans << nline;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	cout << fixed << setprecision(10);
	int _ = 1;
	sieve();
	cin >> _;
	while (_--) {blackout_yash();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}