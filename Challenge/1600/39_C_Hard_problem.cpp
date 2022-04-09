// C. Hard problem
// Link - https://codeforces.com/contest/706/problem/C



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
#define pf push_front
#define int long long
#define mn ((-9)*1e18)
#define MOD 1000000007
using namespace chrono;
#define unsigned int32_t
#define size(x) (x).size()
#define double long double
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

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
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------*/


void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n;
	cin >> n;

	vector <int> cost(n);
	for (auto &xx : cost) cin >> xx;

	vector <vector<string>> s(n, vector<string> (2));
	fora(i, 0, n) {
		string x; cin >> x;
		s[i][0] = x;
		reverse(all(x));
		s[i][1] = x;
	}

	vector <vector<int>> dp(n, vector<int> (2, -1));
	fora(i, 0, n) {
		fora(j, 0, 2) {
			if (i) {
				int ans1 = -1, ans2 = -1;
				if (s[i][j] >= s[i - 1][0] && dp[i - 1][0] != -1) ans1 = dp[i - 1][0];
				if (s[i][j] >= s[i - 1][1] && dp[i - 1][1] != -1) ans2 = dp[i - 1][1];

				if (ans1 == ans2) {
					if (ans1 == -1) dp[i][j] = -1;
					else dp[i][j] = min(ans1, ans2);
				} else if (ans1 != -1 && ans2 != -1) dp[i][j] =  min(ans1, ans2);
				else if (ans1 == -1) dp[i][j] = ans2;
				else dp[i][j] = ans1;

				if (j && dp[i][j] != -1 && s[i][0] != s[i][1]) dp[i][j] += cost[i];
			} else {
				dp[0][0] = dp[0][1] = 0;
				if (s[0][0] != s[0][1]) dp[0][1] = cost[i];
			}
		}
	}

	int ans = mm;
	for (auto x : dp[n - 1]) {
		if (x != -1) ans = min(ans, x);
	}(ans == mm) ? cout << -1 : cout << ans;
	cout << nline;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	int tt = 1;
	// cin >> tt;
	while (tt--) {solve();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}