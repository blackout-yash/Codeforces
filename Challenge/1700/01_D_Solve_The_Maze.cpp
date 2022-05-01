// D. Solve The Maze
// Link - https://codeforces.com/problemset/problem/1365/D



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
const int n = 60;
int vis[n][n], store[n][n];
string temp[n];

bool isValid(int i, int j, int n, int m) {
	return i >= 0 && i < n && j >= 0 && j < m;
}

bool posible(int i, int j, int n, int m) {
	if (isValid(i, j, n, m)) {
		if (!vis[i][j] && temp[i][j] != '#') return true;
	} return false;
}

vector <pair<int, int>> movements = {
	{1, 0}, { -1, 0},
	{0, 1}, {0, -1}
};

void update(int flag) {
	fora(i, 0, n) {
		fora(j, 0, n) {
			if (vis[i][j]) {
				if (flag) store[i][j] = 1;
				else store[i][j] = 0;
			}
		}
	}
}

bool bfs(int x, int y, int n, int m) {
	if (!posible(x, y, n, m)) return false;
	else if (store[x][y] != -1) return store[x][y];

	vis[x][y] = 1;

	queue <pair<int, int>> q;
	q.push({x, y});

	bool flag = false;
	while (!q.empty()) {
		pair<int, int> curr = q.front();
		q.pop();

		int currX = curr.ff, currY = curr.ss;
		for (auto x : movements) {
			int tempX = currX + x.ff, tempY = currY + x.ss;

			if (!posible(tempX, tempY, n, m)) continue;
			else if (tempX + 1 == n && tempY + 1 == m) {flag = 1; break;}

			vis[tempX][tempY] = 1;
			q.push({tempX, tempY});
		} if (flag) break;
	}

	if (flag) update(1);
	else update(0);

	return flag;
}

void clear() {
	fora(i, 0, n) {
		fora(j, 0, n) vis[i][j] = 0;
	}
}

void _set() {
	fora(i, 0, n) {
		fora(j, 0, n) store[i][j] = -1;
	}
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	_set();
	int n, m;
	cin >> n >> m;

	string s[n];
	for (auto &xx : s) cin >> xx;
	fora(i, 0, n) temp[i] = s[i];

	fora(i, 0, n) {
		fora(j, 0, m) {
			if (s[i][j] == 'B') {
				for (auto x : movements) {
					int tempX = i + x.ff, tempY = j + x.ss;
					if (isValid(tempX, tempY, n, m))
						temp[tempX][tempY] = '#';
				}
			} else if (s[i][j] == '#') temp[i][j] = '#';
		}
	}

	bool ans = 1;
	fora(i, 0, n) {
		fora(j, 0, m) {
			if (s[i][j] == 'G') {
				clear();
				if (bfs(i, j, n, m)) {}
				else {ans = 0; break;}
			}
		} if (!ans) break;
	} (ans) ? cout << "Yes" : cout << "No";
	cout << nline;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	int tt = 1;
	cin >> tt;
	while (tt--) {solve();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}