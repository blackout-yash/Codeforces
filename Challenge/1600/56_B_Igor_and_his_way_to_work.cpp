// B. Igor and his way to work
// Link - https://codeforces.com/contest/793/problem/B



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
#define mm (99)
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
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------*/
const int n = 1e3 + 10;
bool vis[n][n][4][3], flag = 0;
vector <string> s(n);

bool isValid(int i, int j, int dir, int ans, int n, int m) {
	if (i >= 0 && i < n && j >= 0 && j < m && ans <= 2) {
		if (s[i][j] != '*' && !vis[i][j][dir][ans] && !flag) return true;
	} return false;
}

void solve(int i, int j, int dir, int ans, int n, int m) {
	if (isValid(i, j, dir, ans, n, m)) vis[i][j][dir][ans] = 1;
	else return;

	if (s[i][j] == 'T') {
		flag = 1;
		return;
	}

	if (dir == 1) {
		solve(i, j + 1, 1, ans, n, m);
		solve(i + 1, j, 2, ans + 1, n, m);
		solve(i, j - 1, 3, ans + 1, n, m);
		solve(i - 1, j, 4, ans + 1, n, m);
	} else if (dir == 2) {
		solve(i, j + 1, 1, ans + 1, n, m);
		solve(i + 1, j, 2, ans, n, m);
		solve(i, j - 1, 3, ans + 1, n, m);
		solve(i - 1, j, 4, ans + 1, n, m);
	} else if (dir == 3) {
		solve(i, j + 1, 1, ans + 1, n, m);
		solve(i + 1, j, 2, ans + 1, n, m);
		solve(i, j - 1, 3, ans, n, m);
		solve(i - 1, j, 4, ans + 1, n, m);
	} else {
		solve(i, j + 1, 1, ans + 1, n, m);
		solve(i + 1, j, 2, ans + 1, n, m);
		solve(i, j - 1, 3, ans + 1, n, m);
		solve(i - 1, j, 4, ans, n, m);
	}
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n, m;
	cin >> n >> m;

	int sx = 0, sy = 0;
	fora(i, 0, n) {
		string x; cin >> x;
		s[i] = x;
		fora(j, 0, m) {
			if (x[j] == 'S') sx = i, sy = j;
		}
	}

	solve(sx, sy + 1, 1, 0, n, m);
	solve(sx + 1, sy, 2, 0, n, m);
	solve(sx, sy - 1, 3, 0, n, m);
	solve(sx - 1, sy, 4, 0, n, m);

	if (flag) cout << "YES";
	else cout << "NO";
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