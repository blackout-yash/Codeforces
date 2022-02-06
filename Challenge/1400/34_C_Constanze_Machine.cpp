// C. Constanze's Machine
// Link - https://codeforces.com/problemset/problem/1245/C



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

vector <int> fib(1e5 + 100);
void solve() {
	fib[0] = 0; fib[1] = fib[2] = 1;
	fora(i, 3, 1e5 + 100) fib[i] = (fib[i - 1] % MOD + fib[i - 2] % MOD) % MOD;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/

	solve();
	string s;
	cin >> s;

	int ans = 1, n = 0, u = 0;
	fora(i, 0, size(s)) {
		if (s[i] == 'w' || s[i] == 'm') {
			ans = 0; break;
		} else if (s[i] == 'n') n++;
		else if (s[i] == 'u') u++;

		if (n && (i + 1 == size(s) || s[i] != 'n')) {
			ans = ((ans % MOD) * (fib[n + 1] % MOD)) % MOD; n = 0;
		}

		if (u && (i + 1 == size(s) || s[i] != 'u')) {
			ans = ((ans % MOD) * (fib[u + 1] % MOD)) % MOD; u = 0;
		}
	} cout << ans;

	return 0;
}