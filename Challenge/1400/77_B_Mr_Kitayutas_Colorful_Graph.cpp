// B. Mr. Kitayuta's Colorful Graph
// Link - https://codeforces.com/problemset/problem/505/B



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
const int n = 1e3;
vector <int> graph[n + 1];
map<pair<int, int>, vector <int>> store;
vector <int> vis(n);

bool check(int col, vector <int> &arr) {
	for (auto x : arr) {
		if (x == col) return true;
	} return false;
}

bool dfs(int root, int des, int col) {
	vis[root] = 1;
	if (root == des) return true;

	for (int child : graph[root]) {
		if (vis[child]) continue;
		else if (check(col, store[ {child, root}])) {
			if (dfs(child, des, col)) return true;
		}
	} return false;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/

	int n, m;
	cin >> n >> m;

	int range = m;
	while (range--) {
		int v1, v2, col;
		cin >> v1 >> v2 >> col;

		graph[v1].pb(v2);
		graph[v2].pb(v1);
		store[ {v1, v2}].pb(col);
		store[ {v2, v1}].pb(col);
	}

	int tt;
	cin >> tt;
	while (tt--) {
		int x, y, ans = 0;
		cin >> x >> y;
		fora(i, 1, m + 1) {
			if (dfs(x, y, i)) ans++;
			fora(j, 1, n + 1) vis[j] = 0;
		} cout << ans << nline;
	}

	return 0;
}