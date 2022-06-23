// C. Portal
// Link - https://codeforces.com/contest/1581/problem/C



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
#define int long long
#define mn ((-9)*1e18)
#define lb lower_bound
#define ub upper_bound
#define MOD 1000000007
using namespace chrono;
#define bs binary_search
#define size(x) (x).size()
#define double long double
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
// typedef tree <int, null_type, less <int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
// typedef tree <pair<int, int>, null_type, less <pair <int, int>>, rb_tree_tag, tree_order_statistics_node_update > multipbds;

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x << " => "; _pprintt(x); cerr << endl;
#else
#define debug(x)
#endif

void _pprintt(int t) {cerr << t;}
void _pprintt(string t) {cerr << t;}
void _pprintt(char t) {cerr << t;}
void _pprintt(double t) {cerr << t;}
void _pprintt(bool t) {cerr << t;}

template <class T, class V> void _pprintt(pair <T, V> p);
template <class T> void _pprintt(vector <T> v);
template <class T> void _pprintt(set <T> v);
template <class T, class V> void _pprintt(map <T, V> v);
template <class T> void _pprintt(multiset <T> v);
template <class T, class V> void _pprintt(pair <T, V> p) {cerr << "{"; _pprintt(p.ff); cerr << ","; _pprintt(p.ss); cerr << "}";}
template <class T> void _pprintt(vector <T> v) {cerr << "[ "; for (T i : v) {_pprintt(i); cerr << " ";} cerr << "]\n";}
template <class T> void _pprintt(set <T> v) {cerr << "[ "; for (T i : v) {_pprintt(i); cerr << " ";} cerr << "]";}
template <class T> void _pprintt(multiset <T> v) {cerr << "[ "; for (T i : v) {_pprintt(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _pprintt(map <T, V> v) {cerr << "[ "; for (auto i : v) {_pprintt(i); cerr << " ";} cerr << "]";}
// void _pprintt(pbds v) {cerr << "[ "; for (auto i : v) {_pprintt(i); cerr << " ";} cerr << "]";}
// void _pprintt(multipbds v) {cerr << "[ "; for (auto i : v) {_pprintt(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------*/
int arr[401][401], dp[401];

int sum(int i1, int j1, int i2, int j2) {
	return arr[i2][j2] - arr[i1 - 1][j2] - arr[i2][j1 - 1] + arr[i1 - 1][j1 - 1];
}

void blackout_yash() {
	/*-------__👌Never Give Up👌__-------*/
	/*----__🤭🤭Stop Stalking🤭🤭__----*/


	int n, m;
	cin >> n >> m;

	fora(i, 1, n + 1) {
		fora(j, 1, m + 1) {
			char ch; cin >> ch;
			arr[i][j] = arr[i - 1][j] + arr[i][j - 1] - arr[i - 1][j - 1] + (ch == '1');
		}
	}

	int ans = mm;
	fora(i, 1, n + 1) {
		fora(j, i + 4, n + 1) {
			fora(k, 4, m + 1) {
				int sum1 = sum(i + 1, 1, j - 1, k - 1),
				    sum2 = sum(i, 1, i, k - 1),
				    sum3 = sum(j, 1, j, k - 1),
				    sum4 = sum(i + 1, k, j - 1, k),
				    hort = j - i - 1,
				    vert = 2 * (k - 1);

				dp[k] = sum1 + (vert - sum2 - sum3) + (hort - sum4);
			}

			rfora(k, 4, m) dp[k] = min(dp[k], dp[k + 1]);

			fora(k, 1, m - 2) {
				int sum1 = sum(i + 1, k, j - 1, k),
				    sum2 = sum(i + 1, 1, j - 1, k),
				    sum3 = sum(i, 1, i, k),
				    sum4 = sum(j, 1, j, k),
				    hort = j - i - 1,
				    vert = 2 * k;

				int temp = dp[k + 3] + (hort - sum1) - sum2 - (vert - sum3 - sum4);
				ans = min(ans, temp);
			}
		}
	} cout << ans << nline;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	// cout << fixed << setprecision(10);
	int _ = 1;
	cin >> _;
	while (_--) {blackout_yash();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}