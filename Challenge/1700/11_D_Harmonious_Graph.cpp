// D. Harmonious Graph
// Link - https://codeforces.com/contest/1253/problem/D?f0a28=1



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
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------*/
const int n = 3 * 1e5;
vector <vector<int>> graph(n);
vector <int> vis(n), path;

void dfs(int root) {
	vis[root] = 1;

	path.pb(root);
	for (int child : graph[root]) {
		if (vis[child]) continue;
		dfs(child);
	}
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n, m;
	cin >> n >> m;

	fora(i, 0, m) {
		int u, v;
		cin >> u >> v;

		graph[u].pb(v);
		graph[v].pb(u);
	}

	set <pair<int, int>> arr;
	fora(i, 1, n + 1) {
		if (vis[i]) {}
		else {
			dfs(i);
			int _max = *max_element(all(path));
			int _min = *min_element(all(path));
			arr.insert({_min, _max});
			path.clear();
		}
	}

	int ans = 0;
	while (size(arr) > 1) {
		vector <pair<int, int>> temp;
		int l = -1, r = -1;
		for (auto x : arr) {
			int start = x.ff, end = x.ss;
			if (l == r && l == -1) {
				if (start != end) {
					l = start, r = end;
					temp.pb({start, end});
				}
			} else if ((end >= l && end <= r) || (start >= l && start <= r)) {
				l = min(l, start); r = max(r, end);
				temp.pb({start, end});
				ans++;
			} else break;
		} if (l == r && l == -1) break;
		for (auto x : temp) arr.erase(x);
	} cout << ans;
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