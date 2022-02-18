// B. Jumping on Walls
// Link - https://codeforces.com/contest/198/problem/B



/*--------------------------------------👻 Yash 👻--------------------------------------*/
// #pragma GCC optimize("Ofast")
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
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);

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
const int n = 3 * 1e5;
vector <vector<int>> vis(2, vector<int> (n, -1));

void solve() {
	/*-------👌Never Give Up👌-------*/
	int n, k; string str[2];
	cin >> n >> k >> str[0] >> str[1];

	queue <pair<int, int>> q;
	q.push({0, 0}); vis[0][0] = 0;

	while (!q.empty()) {
		int x = q.front().ff, y = q.front().ss;
		q.pop();
		if (y >= n) {cout << "YES"; return;}

		int water = vis[x][y];
		if (str[x][y] == 'X' || water > y) continue;

		if (vis[!x][min(y + k, n)] == -1) {
			vis[!x][min(y + k, n)] = water + 1;
			q.push({!x, min(y + k, n)});
		}
		if (vis[x][y + 1] == -1) {
			vis[x][y + 1] = water + 1;
			q.push({x, y + 1});
		}
		if (y && vis[x][y - 1] == -1) {
			vis[x][y - 1] = water + 1;
			q.push({x, y - 1});
		}
	} cout << "NO";
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	solve();
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}