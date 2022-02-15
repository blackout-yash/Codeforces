// B. Strongly Connected City
// Link - https://codeforces.com/contest/475/problem/B



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
const int n = 30;
vector <int> hor(n), ver(n);
vector <vector<int>> vis(n, vector<int> (n));

bool isValid(int x, int y, int n, int m) {
	return x > 0 && x <= m && y > 0 && y <= n;
}

bool dfs(int x1, int y1, int x2, int y2, int n, int m) {
	vis[x1][y1] = 1;
	if (x1 == x2 && y1 == y2) return true;

	int curr_X = x1 + hor[y1], curr_Y = y1 + ver[x1];
	debug(mp(curr_X, curr_Y))
	if (isValid(curr_X, y1, n, m) && !vis[curr_X][y1]) {
		if (dfs(curr_X, y1, x2, y2, n, m)) return true;
	}
	if (isValid(x1, curr_Y, n, m) && !vis[x1][curr_Y]) {
		if (dfs(x1, curr_Y, x2, y2, n, m)) return true;
	} return false;
}

void reset(int n, int m) {
	fora(i, 1, m + 1) {
		fora(j, 1, n + 1) vis[i][j] = 0;
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
	fora(i, 1, n + 1) {
		char ch; cin >> ch;
		if (ch == '>') hor[i] = 1;
		else hor[i] = -1;
	}
	fora(i, 1, m + 1) {
		char ch; cin >> ch;
		if (ch == 'v') ver[i] = 1;
		else ver[i] = -1;
	}

	int flag = 1;
	fora(i, 1, m + 1) {
		fora(j, 1, n + 1) {
			fora(k, 1, m + 1) {
				fora(l, 1, n + 1) {
					flag = dfs(i, j, k, l, n, m);
					reset(n, m);
					if (!flag) break;
				} if (!flag) break;
			} if (!flag) break;
		} if (!flag) break;
	}(flag) ? cout << "YES\n" : cout << "NO\n";

	return 0;
}