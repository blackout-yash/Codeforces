// C. Water the Trees
// Link - https://codeforces.com/problemset/problem/1661/C



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


bool solve(int one, int two, int max, vector <int> &arr) {
	for (auto x : arr) {
		int diff = max - x, div = diff / 2;

		if (two >= div) {
			two -= div;
			if (diff & 1) {
				if (one) one--;
				else return false;
			}
		} else {
			diff -= (2 * two); two = 0;
			if (diff <= one) one -= diff;
			else return false;
		}
	} return true;
}


void blackout_yash() {
	/*-------__👌Never Give Up👌__-------*/
	/*----__🤭🤭Stop Stalking🤭🤭__----*/


	int n;
	cin >> n;

	vector <int> arr(n);
	for (auto &xx : arr) cin >> xx;

	int _max = *max_element(all(arr)), ans = mm;
	fora(i, _max, _max + 10) {
		int low = 0, high = 1e18;
		while (low <= high) {
			int mid = low + (high - low) / 2, one = mid / 2, two = mid / 2;
			if (mid & 1) one++;

			if (solve(one, two, i, arr)) {
				ans = min(ans, mid);
				high = mid - 1;
			} else low = mid + 1;
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
	cin >> _;
	while (_--) {blackout_yash();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}