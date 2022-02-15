// C. Not Assigning
// Link - https://codeforces.com/problemset/problem/1627/C



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
const int n = 1e6;
int vis[n], level [n];
vector <int> path;

void dfs(int root, vector <vector <int>> &graph) {
	vis[root] = 1;
	path.pb(root);

	for (int child : graph[root]) {
		if (vis[child]) continue;
		level[child] = 1 + level[root];
		dfs(child, graph);
	}
}

void reset(int n) {
	fora(i, 1, n + 1) vis[i] = 0;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;

		vector <vector<int>> graph(n + 1);
		map <pair<int, int>, int> store;
		fora(i, 1, n) {
			int v1, v2;
			cin >> v1 >> v2;

			store[ {v1, v2}] = i;
			graph[v1].pb(v2);
			graph[v2].pb(v1);
		}

		int flag = 1;
		fora(i, 1, n + 1) {
			if (size(graph[i]) > 2) {
				flag = 0;
				break;
			}
		}

		if (flag) {
			dfs(1, graph);

			int maxHeight = -1, node;
			fora(i, 1, n + 1) {
				if (level[i] > maxHeight) {
					maxHeight = level[i];
					node = i;
				} vis[i] = 0;
			} path.clear();
			dfs(node, graph);

			vector <int> ans(n + 1);
			int num = 3;
			fora(i, 1, size(path)) {
				if (store[ {path[i], path[i - 1]}]) ans[store[ {path[i], path[i - 1]}]] = num;
				else ans[store[ {path[i - 1], path[i]}]] = num;

				if (num == 3) num = 2;
				else num = 3;
			} path.clear(); reset(n);

			for (auto x : ans) (x) ? cout << x << " " : cout << "";
			cout << nline;
		} else cout << -1 << nline;
	}

	return 0;
}