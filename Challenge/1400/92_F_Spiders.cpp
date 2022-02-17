// F. Spiders
// Link - https://codeforces.com/problemset/problem/120/F



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
vector <int> graph[n];
int vis[n], height[n], maximum;

void dfs(int root) {
	vis[root] = 1;

	for (int child : graph[root]) {
		if (vis[child]) continue;
		height[child] = 1 + height[root];
		maximum = max(maximum, height[child]);
		dfs(child);
	}
}

void reset(int n) {
	fora(i, 1, n + 1) vis[i] = height[i] = 0;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	/*-------👌Never Give Up👌-------*/

	int tt, ans = 0;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		fora(i, 1, n) {
			int v1, v2;
			cin >> v1 >> v2;

			graph[v1].pb(v2);
			graph[v2].pb(v1);
		} maximum = 0;
		fora(i, 1, n + 1) {
			dfs(i); reset(n);
		} ans += maximum;
		fora(i, 1, n + 1) graph[i].clear();
	} cout << ans;


	return 0;
}