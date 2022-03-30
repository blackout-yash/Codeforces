// C1. Guessing the Greatest (easy version)
// Link - https://codeforces.com/contest/1486/problem/C1



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
#define pf push_front
#define int long long
#define mn ((-9)*1e18)
#define MOD 1000000007
using namespace chrono;
#define unsigned int32_t
#define size(x) (x).size()
#define double long double
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " => "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(bool t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------*/
void solve(int low, int mid, int high, int index1, int index2, int &ans) {
	if (index1 == low || index2 == low) low = -1;
	if (index1 == mid || index2 == mid) mid = -1;
	if (index1 == high || index2 == high) high = -1;

	if (low != -1) ans = low;
	if (mid != -1) ans = mid;
	if (high != -1) ans = high;
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n;
	cin >> n;

	map <pair<int, int>, int> m;
	int low = 1, high = n, ans = 1;
	while (low < high) {
		int mid = low + (high - low) / 2, index1, index2, index3;

		if (m.count({low, high})) index1 = m[ {low, high}];
		else {
			cout << "? " << low << " " << high << endl;
			cin >> index1;
			m[ {low, high}] = index1;
		}

		if (low + 1 == high) {
			if (index1 == low) ans = high;
			else ans = low;
			break;
		} else {
			if (m.count({low, mid})) index2 = m[ {low, mid}];
			else {
				cout << "? " << low << " " << mid << endl;
				cin >> index2;
				m[ {low, mid}] = index2;
			}

			if (low + 1 == mid && high - low == 2) {
				if (index1 != index2) solve(low, mid, high, index1, index2, ans);
				else solve(low, mid, high, index1, high, ans);
				break;
			} else if (index1 == index2) high = mid;
			else {
				if (m.count({mid + 1, high})) index3 = m[ {mid + 1, high}];
				else {
					cout << "? " << mid + 1 << " " << high << endl;
					cin >> index3;
					m[ {mid + 1, high}] = index3;
				}

				if (index1 == index3) low = mid + 1;
				else if (low <= index1 && index1 <= mid) {
					if (index2 == index3) high = mid;
					else low = mid + 1;
				} else {
					if (index2 != index3) high = mid;
					else low = mid + 1;
				}
			}
		}
	} cout << "! " << ans << endl;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	int tt = 1;
	// cin >> tt;
	while (tt--) {solve();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}