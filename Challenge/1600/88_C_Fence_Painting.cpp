// C. Fence Painting
// Link - https://codeforces.com/contest/1481/problem/C



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


void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n, m;
	cin >> n >> m;

	vector <int> a(n), b(n), c(m);
	for (auto &xx : a) cin >> xx;

	map <int, vector <int>> needed;
	map <int, int> store, total;
	fora(i, 0, n) {
		cin >> b[i];

		total[b[i]] = i + 1;
		if (a[i] != b[i]) needed[b[i]].pb(i + 1);
	}

	vector <int> ans(m), arr;
	fora(i, 0, m) {
		cin >> c[i];

		if (size(needed[c[i]]) == store[c[i]]) {
			if (total.count(c[i])) {
				int j = 0, index = total[c[i]];
				while (j != size(arr)) {
					ans[arr[j]] = index;
					j++;
				} arr.clear();

				ans[i] = index;
			} else arr.pb(i);
		} else {
			int j = 0, index = store[c[i]], num = needed[c[i]][index];
			while (j != size(arr)) {
				ans[arr[j]] = num;
				j++;
			} arr.clear();

			ans[i] = num;
			store[c[i]]++;
		}
	}

	if (*min_element(all(ans))) {
		vector <int> temp = a;
		fora(i, 0, m) {
			temp[ans[i] - 1] = c[i];
		}

		if (temp == b) {
			cout << "YES\n";
			for (auto x : ans) cout << x << " ";
		} else cout << "NO";
	} else cout << "NO";
	cout << nline;
}



int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	int tt = 1;
	cin >> tt;
	while (tt--) {solve();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}