// B. You Are Given a Decimal String...
// Link - https://codeforces.com/problemset/problem/1202/B



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
vector <vector<int>> vis(10, vector<int> (10));

void bfs(int x, int y, int root) {
	queue <int> q;
	q.push(root);
	vis[root][root] = 0;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		int sum1 = (curr + x) % 10, sum2 = (curr + y) % 10;
		if (vis[root][sum1] == -1 && x) {
			q.push(sum1);
			vis[root][sum1] = 1 + vis[root][curr];
		}

		if (vis[root][sum2] == -1 && y) {
			q.push(sum2);
			vis[root][sum2] = 1 + vis[root][curr];
		}

		if (sum1 == root || sum2 == root) {
			if (vis[root][root]) vis[root][root] = min(vis[root][root], 1 + vis[root][curr]);
			else vis[root][root] = 1 + vis[root][curr];
		}
	}
}

void reset() {
	for (auto &x : vis) {
		for (auto &y : x) y = -1;
	}
}

void blackout_yash() {
	/*-------__👌Never Give Up👌__-------*/
	/*----__🤭🤭Stop Stalking🤭🤭__----*/

	string s;
	cin >> s;

	int n = size(s);
	vector <vector<int>> ans(10, vector<int> (10));

	if (n > 1) {
		fora(i, 0, 10) {
			fora(j, 0, 10) {
				if (!ans[i][j]) {
					reset();
					fora(k, 0, 10) bfs(i, j, k);

					int total = 0;
					fora(k, 0, n - 1) {
						int num1 = s[k] - '0', num2 = s[k + 1] - '0', temp = vis[num1][num2] - 1;
						if (temp < 0) {
							total = -1;
							break;
						} else total += temp;
					} ans[i][j] = total;
				}
			}
		}
	}

	for (auto x : ans) {
		for (auto y : x) cout << y << " ";
		cout << nline;
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
	while (_--) {blackout_yash();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}