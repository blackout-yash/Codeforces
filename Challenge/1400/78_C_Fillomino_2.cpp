// C. Fillomino 2
// Link - https://codeforces.com/problemset/problem/1517/C



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
vector <vector<int>> graph(n, vector<int> (n));

isValid(int x, int y, int n) {
	return x > 0 && x <= n && y > 0 && y <= n;
}

vector <pair<int, int>> movements = {
	{ 1, 0}, { 0, -1}
};

bool dfs(int x, int y, int n, int num, int &range) {
	graph[x][y] = num; range--;
	if (range == 0) return true;

	for (auto movement : movements) {
		int hor = x + movement.ff, vert = y + movement.ss;
		if (isValid(hor, vert, n)) {
			if (graph[hor][vert] == 0) {
				if (dfs(hor, vert, n, num, range)) return true;
			}
		}
	} return false;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/

	int n;
	cin >> n;
	fora(i, 1, n + 1) cin >> graph[i][i];

	rfora(i, 1, n + 1) {
		int range = graph[i][i];
		dfs(i, i, n, graph[i][i], range);
	}

	fora(i, 1, n + 1) {
		fora(j, 1, i + 1) cout << graph[i][j] << " ";
		cout << nline;
	}

	return 0;
}