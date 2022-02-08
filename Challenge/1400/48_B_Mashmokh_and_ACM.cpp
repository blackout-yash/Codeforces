// B. Mashmokh and ACM
// Link - https://codeforces.com/problemset/problem/414/B



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

vector <int> factors(int n) {
	vector <int> factor;
	for (int i = 1; i <= sqrt(n); i++) {
		if (n % i == 0) {
			if (n / i != i) factor.pb(n / i);
			factor.pb(i);
		}
	} return factor;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n, k;
	cin >> n >> k;

	vector <vector<int>> dp(n + 1, vector <int>(k + 1)), sum(n + 1, vector <int>(k + 1));
	fora(i, 1, n + 1) {
		vector <int> factor = factors(i);
		fora(j, 1, k + 1) {
			if (i == 1) dp[i][j] = 1;
			else {
				dp[i][j] = 1;
				if (j == 1) {}
				else {
					for (auto x : factor) {
						if (x == 1) {}
						else dp[i][j] = ((dp[i][j] % MOD) + (sum[i / x][j - 1] % MOD)) % MOD;
					}
				}
			} if (j == 1) sum[i][j] = dp[i][j];
			else sum[i][j] = ((sum[i][j - 1] % MOD) + (dp[i][j] % MOD)) % MOD;
		}
	}

	int ans = 0;
	fora(i, 1, n + 1) ans = ((ans % MOD) + (dp[i][k] % MOD)) % MOD;
	cout << ans;

	return 0;
}