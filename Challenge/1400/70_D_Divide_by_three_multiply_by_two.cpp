// D. Divide by three, multiply by two
// Link - https://codeforces.com/problemset/problem/977/D



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
map <int, vector <int>> m;
vector <int> path;
map <int, int> vis;

void dfs(int root) {
	path.pb(root);
	vis[root] = 1;

	vector <int> store = m[root];
	for (int child : store) {
		if (vis[child]) continue;
		dfs(child);
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n;
	cin >> n;
	vector <int> arr(n);
	fora(i, 0, n) cin >> arr[i];
	sort(all(arr));

	fora(i, 0, n) {
		int num = arr[i];
		if (binary_search(all(arr), 2 * num)) {
			m[num].pb(2 * num);
			m[2 * num].pb(num);
		}

		if (num % 3 == 0) {
			if (binary_search(all(arr), num / 3)) {
				m[num].pb(num / 3);
				m[num / 3].pb(num);
			}
		}
	}

	for (auto x : m) {
		dfs(x.ff);
		if (size(path) == n) {
			int flag = 1;
			fora(i, 1, size(path)) {
				if (path[i] == 2 * path[i - 1]) {}
				else if (path[i - 1] % 3 == 0 && path[i - 1] == 3 * path[i]) {}
				else {
					flag = 0; break;
				}
			}
			if (flag) {
				for (auto y : path) cout << y << " ";
				break;
			}
		} path.clear(); vis.clear();
	}

	return 0;
}