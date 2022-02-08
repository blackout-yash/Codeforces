// B. Mike and Fun
// Link - https://codeforces.com/problemset/problem/548/B



/*--------------------------------------👻 Yash 👻--------------------------------------*/
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


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n, m, q;
	cin >> n >> m >> q;
	vector <vector <int>> arr(n, vector <int> (m));
	vector <int> store(n);
	fora(i, 0, n) {
		fora(j, 0, m) cin >> arr[i][j];
	}

	fora(i, 0, n) {
		int one = 0;
		fora(j, 0, m) {
			if (arr[i][j]) one++;
			else one = 0;
			store[i] = max(store[i], one);
		}
	}

	while (q--) {
		int l, r;
		cin >> l >> r;

		if (arr[l - 1][r - 1]) arr[l - 1][r - 1] = 0;
		else arr[l - 1][r - 1] = 1;

		int one = 0; store[l - 1] = 0;
		fora(i, 0, m) {
			if (arr[l - 1][i]) one++;
			else one = 0;
			store[l - 1] = max(store[l - 1], one);
		}

		int ans = 0;
		for (auto x : store) ans = max(ans, x);
		cout << ans << nline;
	}

	return 0;
}