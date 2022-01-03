// B. Ternary Sequence
// Link - https://codeforces.com/problemset/problem/1401/B



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

void solve(int a[], int b[], int i, int j) {
	if (a[i] > b[j]) {
		a[i] -= b[j]; b[j] = 0;
	} else {
		b[j] -= a[i]; a[i] = 0;
	}
}

void sum(int a[], int b[], int i, int j, int &ans, int mult) {
	if (a[i] > b[j]) {
		ans += (mult * b[j] * 2);
		a[i] -= b[j]; b[j] = 0;
	} else {
		ans += (mult * a[i] * 2);
		b[j] -= a[i]; a[i] = 0;
	}
}


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
		int a[3], b[3], ans = 0;
		fora(i, 0, 3) cin >> a[i];
		fora(i, 0, 3) cin >> b[i];

		sum(a, b, 2, 1, ans, 1);
		solve(a, b, 2, 2);
		solve(a, b, 2, 0);

		solve(a, b, 1, 1);
		solve(a, b, 1, 0);

		solve(a, b, 0, 2);
		solve(a, b, 0, 1);
		solve(a, b, 0, 0);

		sum(a, b, 1, 2, ans, -1);
		cout << ans << nline;
	}

	return 0;
}