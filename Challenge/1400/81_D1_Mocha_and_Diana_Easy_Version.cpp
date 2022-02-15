// D1. Mocha and Diana (Easy Version)
// Link - https://codeforces.com/problemset/problem/1559/D1



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
const int n = 1e4;
vector <vector <int>> graph1(n), graph2(n);
vector <int> vis1(n), vis2(n);

void dfs(int root, vector <int> &vis, vector <vector <int>> &graph) {
	vis[root] = 1;

	for (int child : graph[root]) {
		if (vis[child]) continue;
		dfs(child, vis, graph);
	}
}

void input(int m, vector <vector <int>> &graph) {
	while (m--) {
		int v1, v2;
		cin >> v1 >> v2;

		graph[v1].pb(v2);
		graph[v2].pb(v1);
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/

	int n, m1, m2;
	cin >> n >> m1 >> m2;

	input(m1, graph1);
	input(m2, graph2);

	dfs(1, vis1, graph1);
	dfs(1, vis2, graph2);

	vector <pair<int, int>> ans;
	fora(i, 1, n + 1) {
		fora(j, 1, n + 1) {
			if (i != j) {
				bool flag1 = vis1[i], flag2 = vis1[j];
				bool flag3 = vis2[i], flag4 = vis2[j];

				if ((flag1 && !flag2 && flag3 && !flag4) || (!flag1 && flag2 && !flag3 && flag4) || (flag1 && !flag2 && !flag3 && flag4) || (!flag1 && flag2 && flag3 && !flag4)) {
					ans.pb({i, j});
					dfs(i, vis1, graph1);
					dfs(j, vis1, graph1);
					dfs(i, vis2, graph2);
					dfs(j, vis2, graph2);
				}
			}
		}
	}

	cout << size(ans) << nline;
	for (auto x : ans) cout << x.ff << " " << x.ss << nline;

	return 0;
}