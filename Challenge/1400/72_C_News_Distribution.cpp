// C. News Distribution
// Link - https://codeforces.com/contest/1167/problem/C



/*--------------------------------------👻 Yash 👻--------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
#define int long long
#define nline "\n"
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define mm (9*1e18)
#define mn ((-9)*1e18)
#define unsigned int32_t
#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)

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
/*----------------------------------------------------------------------------------------*/
vector <int> path;

void dfs(int root, vector <vector <int>> &graph, vector <int> &vis) {
	vis[root] = 1;
	path.pb(root);

	for (int child : graph[root]) {
		if (vis[child]) continue;
		dfs(child, graph, vis);
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n, m;
	cin >> n >> m;

	vector <vector <int>> graph(n + 1);
	vector <int> vis(n + 1), ans(n + 1);
	while (m--) {
		int n;
		cin >> n;

		vector <int> store(n);
		fora(i, 0, n) cin >> store[i];

		fora(i, 1, size(store)) {
			graph[store[i]].pb(store[i - 1]);
			graph[store[i - 1]].pb(store[i]);
		}
	}

	fora(i, 1, n + 1) {
		if (ans[i]) {}
		else {
			dfs(i, graph, vis);
			for (auto x : path) ans[x] = size(path);
			path.clear();
		}
	}

	fora(i, 1, n + 1)cout << ans[i] << " ";



	return 0;
}