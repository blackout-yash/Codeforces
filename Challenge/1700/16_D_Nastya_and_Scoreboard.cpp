// D. Nastya and Scoreboard
// Link - https://codeforces.com/contest/1341/problem/D



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
#define MOD 1000000007
using namespace chrono;
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
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------*/
string s[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};


void solve() {
	/*-------__👌Never Give Up👌__-------*/
	/*----__🤭🤭Stop Stalking🤭🤭__----*/


	int n, k;
	cin >> n >> k;
	vector <string> arr(n);
	for (auto &xx : arr) cin >> xx;

	vector <vector<int>> store(n, vector<int> (10, -1));
	fora(i, 0, n) {
		fora(j, 0, 10) {
			int cnt = 0;
			fora(k, 0, 7) {
				if (arr[i][k] == s[j][k]) {}
				else {
					if (arr[i][k] == '1') {
						cnt = -1; break;
					} else cnt++;
				}
			} if (cnt != -1) {
				if (store[i][j] == -1) store[i][j] = cnt;
				else store[i][j] = min(store[i][j], cnt);
			}
		}
	}

	vector <vector<pair<int, int>>> dp(n, vector<pair<int, int>> (k + 1, { -1, -1}));
	rfora(i, 0, n) {
		fora(j, 0, k + 1) {
			if (i + 1 != n) {
				int index, ans = -1;
				fora (l, 0, 10) {
					int val = store[i][l], num = l;
					if (j >= val && val != -1) {
						int temp = num; temp *= 10;
						if (dp[i + 1][j - val].ss != -1) {
							temp += dp[i + 1][j - val].ss;
							if (temp > ans) {
								ans = temp;
								index = j - val;
							}
						}
					}
				}

				if (ans != -1) {
					dp[i][j].ff = index;
					ans /= 10;
					dp[i][j].ss = ans;
				}
			} else {
				fora (l, 0, 10) {
					if (store[i][l] == j) dp[i][j].ss = max(dp[i][j].ss, l);
				}
			}
		}
	}

	vector <int> ans;
	int index = k;
	fora(i, 0, n) {
		int num = dp[i][index].ss;
		if (num == -1) {
			ans.clear(); break;
		} else ans.pb(num);
		index = dp[i][index].ff;
	}


	if (ans.empty()) cout << -1;
	else {
		for (auto x : ans) cout << x;
	}
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	cout << fixed << setprecision(10);
	int _ = 1;
	// cin >> _;
	while (_--) {solve();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}