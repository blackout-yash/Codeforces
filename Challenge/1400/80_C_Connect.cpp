// C. Connect
// Link - https://codeforces.com/problemset/problem/1130/C



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
const int n = 1e2;
vector <vector<int>> road (n, vector<int> (n));
vector <vector<int>> vis1 (n, vector<int> (n)), vis2 (n, vector<int> (n));
vector <pair<int, int>> path1, path2;

vector <pair<int, int>> movements = {
	{0, 1}, {0, -1},
	{1, 0}, { -1, 0}
};

bool isValid(int x, int y, int n) {
	return x > 0 && x <= n && y > 0 && y <= n;
}

void dfs(int x1, int y1, int n, vector <vector<int>> &vis, vector <pair<int, int>> &path) {
	vis[x1][y1] = 1;
	path.pb({x1, y1});

	for (auto movement : movements) {
		int hor = x1 + movement.ff, vert = y1 + movement.ss;
		if (vis[hor][vert]) continue;
		if (isValid(hor, vert, n) && !road[hor][vert]) {
			dfs(hor, vert, n, vis, path);
		}
	}
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n, x1, y1, x2, y2;
	cin >> n >> x1 >> y1 >> x2 >> y2;

	fora(i, 1, n + 1) {
		fora(j, 1, n + 1) {
			char ch; cin >> ch;
			road[i][j] = unsigned(ch - '0');
		}
	}

	dfs(x1, y1, n, vis1, path1);
	dfs(x2, y2, n, vis2, path2);

	int ans = mm;
	for (auto x : path1) {
		int x1 = x.ff, y1 = x.ss;
		for (auto y : path2) {
			int x2 = y.ff, y2 = y.ss;
			ans = min(ans, (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		}
	} cout << ans;

	return 0;
}