// B. Odd sum
// Link - https://codeforces.com/problemset/problem/797/B



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


	int n;
	cin >> n;
	vector <int> arr(n);
	fora(i, 0, n) cin >> arr[i];

	int dp[n][2];
	fora(i, 0, n) {
		if (i == 0) {
			dp[i][0] = dp[i][1] = mn;

			if (arr[i] & 1) dp[i][1] = arr[i];
			else dp[i][0] = arr[i];
		} else {
			dp[i][0] = dp[i - 1][0];
			dp[i][1] = dp[i - 1][1];

			if (arr[i] & 1) {
				dp[i][1] = max(dp[i][1], arr[i]);
				if (dp[i - 1][1] != mn) dp[i][0] = max(dp[i][0], arr[i] + dp[i - 1][1]);
				if (dp[i - 1][0] != mn) dp[i][1] = max(dp[i][1], arr[i] + dp[i - 1][0]);
			} else {
				dp[i][0] = max(dp[i][0], arr[i]);
				if (dp[i - 1][0] != mn) dp[i][0] = max(dp[i][0], arr[i] + dp[i - 1][0]);
				if (dp[i - 1][1] != mn) dp[i][1] = max(dp[i][1], arr[i] + dp[i - 1][1]);
			}
		}
	} cout << dp[n - 1][1];

	return 0;
}