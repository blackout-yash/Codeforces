// A1. Binary Table (Easy Version)
// Link - https://codeforces.com/problemset/problem/1439/A1



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

void insert(int i1, int j1, int i2, int j2, int i3, int j3, vector <vector<int>> &ans) {
	vector <int> temp(6);
	temp[0] = i1; temp[1] = j1; temp[2] = i2;
	temp[3] = j2; temp[4] = i3; temp[5] = j3;
	ans.pb(temp);
}

void solve() {
	/*-------👌Never Give Up👌-------*/

	int n, m;
	cin >> n >> m;
	string s[n];
	vector <vector<int>> ans;
	fora(i, 0, n) cin >> s[i];

	fora(i, 0, n - 1) {
		fora(j, 0, m) {
			if (s[i][j] == '1') {
				s[i][j] = '0';
				if (s[i + 1][j] == '1') s[i + 1][j] = '0';
				else s[i + 1][j] = '1';

				if (j + 1 == m) {
					if (s[i + 1][j - 1] == '1') s[i + 1][j - 1] = '0';
					else s[i + 1][j - 1] = '1';

					insert(i, j, i + 1, j, i + 1, j - 1, ans);
				} else {
					if (s[i + 1][j + 1] == '1') s[i + 1][j + 1] = '0';
					else s[i + 1][j + 1] = '1';

					insert(i, j, i + 1, j, i + 1, j + 1, ans);
				}
			}
		}
	}

	fora(i, 0, m) {
		if (s[n - 1][i] == '1') {
			if (i + 1 == m) {
				s[n - 1][i] = '0';
				insert(n - 2, i - 1, n - 1, i - 1, n - 1, i, ans);
				insert(n - 2, i, n - 1, i, n - 1, i - 1, ans);
				insert(n - 2, i - 1, n - 2, i, n - 1, i, ans);
			} else {
				s[n - 1][i] = '0';
				insert(n - 2, i + 1, n - 1, i + 1, n - 1, i, ans);
				insert(n - 2, i, n - 1, i, n - 1, i + 1, ans);
				insert(n - 2, i + 1, n - 2, i, n - 1, i, ans);
			}
		}
	}
	cout << size(ans) << nline;
	for (auto x : ans) {
		for (auto y : x) cout << y + 1 << " ";
		cout << nline;
	}
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	int tt = 1;
	cin >> tt;
	while (tt--) {solve();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}