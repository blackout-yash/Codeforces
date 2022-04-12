// A. Sum in the tree
// Link - https://codeforces.com/problemset/problem/1098/A



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
const int n = 2 * 1e5;
vector <int> graph[n], vis(n), cost(n), a(n), sum(n), store(n);
bool flag = true;

int dfs(int root) {
	vis[root] = 1;

	int ans = mm;
	for (int child : graph[root]) {
		if (vis[child]) continue;
		ans = min(ans, dfs(child));
	}
	if (ans == mm) ans = 0;
	if (cost[root] > ans) ans = cost[root];
	if (cost[root] != -1 && ans > cost[root]) ans = cost[root];
	store[root] = ans;
	return ans;
}

void nDfs(int root) {
	vis[root] = 1;

	for (int child : graph[root]) {
		if (vis[child]) continue;

		if (sum[root] > store[child] && cost[child] != -1) {
			flag = 0;
			return;
		}

		a[child] = store[child] - sum[root];
		a[child] = max(0 * 1ll, a[child]);
		sum[child] = sum[root] + a[child];
		nDfs(child);
	}
}

void reset(int n) {
	fora(i, 1, n + 1) vis[i] = 0;
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n;
	cin >> n;

	fora(i, 2, n + 1) {
		int x; cin >> x;

		graph[x].pb(i);
		graph[i].pb(x);
	}

	fora(i, 1, n + 1) cin >> cost[i];

	dfs(1); reset(n);
	sum[1] = a[1] = cost[1];
	nDfs(1);

	int ans = 0;
	fora(i, 1, n + 1) ans += a[i];

	if (flag) cout << ans;
	else cout << -1;
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