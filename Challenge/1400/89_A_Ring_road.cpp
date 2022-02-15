// A. Ring road
// Link - https://codeforces.com/contest/24/problem/A



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
map <pair<int, int>, int> m;
vector <int> path;

void dfs(int root, int par = -1) {
	path.pb(root);
	if (size(path) > 1 && path.front() == root) return;

	for (int child : graph[root]) {
		if (child == par) continue;
		dfs(child, root);
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/

	int n, node;
	cin >> n;
	fora(i, 0, n) {
		int v1, v2, c;
		cin >> v1 >> v2 >> c;

		graph[v1].pb(v2);
		graph[v2].pb(v1);
		m[ {v1, v2}] = 0;
		m[ {v2, v1}] = c;
	}

	dfs(1);
	debug(path)
	int min1 = 0, min2 = 0, i = 1;
	while (true) {
		min1 += m[ {path[i - 1], path[i]}];
		if (path[i] == 1) break;
		i++;
	} i++;

	while (true) {
		if (i == size(path)) break;
		else {
			min2 += m[ {path[i - 1], path[i]}];
			i++;
		}
	} cout << min(min1, min2);

	return 0;
}