// A. Parsa's Humongous Tree
// Link - https://codeforces.com/problemset/problem/1528/A



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
struct hash_pair {
	template <class T1, class T2>
	size_t operator()(const pair<T1, T2>& p) const {
		auto hash1 = hash<T1> {}(p.first);
		auto hash2 = hash<T2> {}(p.second);

		if (hash1 != hash2) {
			return hash1 ^ hash2;
		}
		return hash1;
	}
};
/*----------------------------------------------------------------------------------------*/
const int n = 2 * 1e5;
vector <int> vis(n);
unordered_map<pair<int, int>, int, hash_pair> dp;
map <int, pair<int, int>> m;

void movements(int root, vector <int> &num) {
	num.clear();
	num.pb(m[root].ff);
	num.pb(m[root].ss);
}

int dfs(int root, int store, vector <vector<int>> &graph, vector <int> num) {
	vis[root] = 1;
	auto it = dp.find({root, store});
	if (it != dp.end()) return it->ss;

	int ans = 0;
	movements(root, num);
	for (auto x : num) {
		int cnt = 0;
		if (root != 1) cnt = abs(store - x);
		for (int child : graph[root]) {
			if (vis[child]) continue;
			cnt += dfs(child, x, graph, num);
			vis[child] = 0;
		} ans = max(ans, cnt);
	} return dp[ {root, store}] = ans;
}

void reset(int n) {
	fora(i, 0, n + 1) vis[i] = 0;
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n;
	cin >> n;
	m.clear(); reset(n); dp.clear();
	vector <vector<int>> graph(n + 1);
	fora(i, 0, n) {
		int l, r;
		cin >> l >> r;
		m[i + 1] = {l, r};
	}

	fora(i, 1, n) {
		int u, v;
		cin >> u >> v;

		graph[u].pb(v);
		graph[v].pb(u);
	}
	vector <int> num;
	cout << dfs(1, 0, graph, num) << nline;
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