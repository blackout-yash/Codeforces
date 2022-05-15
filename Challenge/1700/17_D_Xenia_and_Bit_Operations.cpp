// D. Xenia and Bit Operations
// Link - https://codeforces.com/contest/339/problem/D



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
int flag1, flag2;
class SGTree {
public:
	vector<int> segment;
	SGTree(int n) {
		segment.resize(4 * n + 1);
	}

	int build(int ind, int low, int high, vector <int> &arr) {
		if (low == high) {
			segment[ind] = arr[low];
			return 0;
		}

		int mid = low + (high - low) / 2;
		int flag1 = build(2 * ind + 1, low, mid, arr);
		int flag2 = build(2 * ind + 2, mid + 1, high, arr);

		if (flag1 && flag2) {
			segment[ind] = (segment[2 * ind + 1] ^ segment[2 * ind + 2]);
			return 0;
		}
		segment[ind] = (segment[2 * ind + 1] | segment[2 * ind + 2]);
		return 1;
	}

	int query(int ind, int low, int high, int l, int r) {
		if (r < low || high < l) return -1;
		if (low >= l && high <= r) {
			flag1 = 0; flag2 = 0;
			return segment[ind];
		}

		int mid = low + (high - low) / 2;
		int left = query(2 * ind + 1, low, mid, l, r);
		int right = query(2 * ind + 2, mid + 1, high, l, r);

		if (left == -1 && right == -1) return -1;
		else if (left != -1 && right != -1) {
			if (flag1 && flag2) {
				flag1 = 0; flag2 = 0;
				return (left ^ right);
			} else {
				flag1 = 1; flag2 = 1;
				return (left | right);
			}
		}
		else if (left == -1) return right;
		return left;
	}

	int update(int ind, int low, int high, int i, int val) {
		if (low == high) {
			segment[ind] = val;
			return 0;
		}

		int mid = low + (high - low) / 2, flag = 0;
		if (i <= mid) flag = update(2 * ind + 1, low, mid, i, val);
		else flag = update(2 * ind + 2, mid + 1, high, i, val);

		if (flag) {
			segment[ind] = (segment[2 * ind + 1] ^ segment[2 * ind + 2]);
			return 0;
		}
		segment[ind] = (segment[2 * ind + 1] | segment[2 * ind + 2]);
		return 1;
	}
};

void blackout_yash() {
	/*-------__👌Never Give Up👌__-------*/
	/*----__🤭🤭Stop Stalking🤭🤭__----*/

	int n, m;
	cin >> n >> m;
	n = ceil(pow(2, n));

	vector <int> arr(n);
	for (auto &xx : arr) cin >> xx;

	SGTree seg(n);
	seg.build(0, 0, n - 1, arr);
	while (m--) {
		int index, val;
		cin >> index >> val;

		seg.update(0, 0, n - 1, index - 1, val);
		cout << seg.query(0, 0, n - 1, 0, n - 1) << nline;
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