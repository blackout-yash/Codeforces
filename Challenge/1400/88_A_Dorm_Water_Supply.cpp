// A. Dorm Water Supply
// Link - https://codeforces.com/contest/107/problem/A



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
vector <int> graph[n];
vector <int> path;
map <pair<int, int>, int> store;

void dfs(int root) {
	path.pb(root);
	if (size(path) > 2 && path[1] == root) {
		path.clear(); return;
	}
	for (int child : graph[root]) {
		path[0] = min(path[0], store[ {root, child}]);
		dfs(child);
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
	while (m--) {
		int v1, v2, c;
		cin >> v1 >> v2 >> c;
		store[ {v1, v2}] = c;
		graph[v1].pb(v2);
	}

	vector <vector<int>> ans;
	fora(i, 1, n + 1) {
		path.pb(mm);
		dfs(i);
		if (size(path) > 2) ans.pb(path);
		path.clear();
	}

	set <pair<pair<int, int>, int>> s;
	fora(i, 0, size(ans)) {
		int start = ans[i][1], end = ans[i].back(), size = size(ans[i]), cost = ans[i].front();
		fora(j, 0, size(ans)) {
			if (i != j) {
				if (end == ans[j].back()) {
					if (size(ans[j]) > size) {
						start = ans[j][1];
						cost = ans[j].front();
						size = size(ans[j]);
					}
				}
			}
		} s.insert({{start, end}, cost});
	} cout << size(s) << nline;
	for (auto x : s) cout << x.ff.ff << " " << x.ff.ss << " " << x.ss << nline;

	return 0;
}