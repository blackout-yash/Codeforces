// B. Putting Bricks in the Wall
// Link - https://codeforces.com/problemset/problem/1421/B



#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define nline "\n"
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define mm INT_MAX
#define mn INT_MIN
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


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	fastio();


	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector <vector <char>> s(n, vector <char>(n));
		fora(i, 0, n) {
			fora(j, 0, n) {
				char c; cin >> c;
				s[i][j] = c;
			}
		}

		vector <pair <int, int>> ans;
again:
		if (s[0][1] == s[1][0]) {
			if (s[0][1] == '0') {
				if (s[n - 2][n - 1] == '0') ans.pb(mp(n - 1, n));
				if (s[n - 1][n - 2] == '0') ans.pb(mp(n, n - 1));
			} else {
				if (s[n - 2][n - 1] == '1') ans.pb(mp(n - 1, n));
				if (s[n - 1][n - 2] == '1') ans.pb(mp(n, n - 1));
			}
		} else if (s[n - 2][n - 1] == s[n - 1][n - 2]) {
			if (s[n - 1][n - 2] == '0') {
				if (s[0][1] == '0') ans.pb(mp(1, 2));
				if (s[1][0] == '0') ans.pb(mp(2, 1));
			} else {
				if (s[0][1] == '1') ans.pb(mp(1, 2));
				if (s[1][0] == '1') ans.pb(mp(2, 1));
			}
		} else {
			if (s[0][1] == '0') {
				ans.pb(mp(2, 1));
				s[1][0] = '0'; goto again;
			} else {
				ans.pb(mp(2, 1));
				s[1][0] = '1'; goto again;
			}
		}
		cout << size(ans) << nline;
		for (auto x : ans) cout << x.ff << " " << x.ss << nline;
	}

	return 0;
}