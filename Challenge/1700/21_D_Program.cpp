// D. Program
// Link - https://codeforces.com/contest/1473/problem/D



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

class LSGTree {
public:
	vector<pair<int, int>> seg;
	vector<int> lazy;
	LSGTree(int n) {
		seg.resize(4 * n + 1);
		lazy.resize(4 * n + 1);
	}

	void build(int ind, int low, int high, vector <int> &arr) {
		if (low == high) {
			seg[ind].ff = arr[low];
			seg[ind].ss = arr[low];
			return;
		}

		int mid = low + (high - low) / 2;
		build(2 * ind + 1, low, mid, arr);
		build(2 * ind + 2, mid + 1, high, arr);

		seg[ind].ff = max(seg[2 * ind + 1].ff, seg[2 * ind + 2].ff);
		seg[ind].ss = min(seg[2 * ind + 1].ss, seg[2 * ind + 2].ss);
	}

	pair<int, int> query(int ind, int low, int high, int l, int r) {
		if (lazy[ind] != 0) {
			seg[ind].ff += lazy[ind];
			seg[ind].ss += lazy[ind];
			if (low != high) {
				lazy[2 * ind + 1] += lazy[ind];
				lazy[2 * ind + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		if (high < l or r < low) return {mn, mm};
		if (low >= l && high <= r) return seg[ind];

		int mid = low + (high - low) / 2;
		pair<int, int> left = query(2 * ind + 1, low, mid, l, r);
		pair<int, int> right = query(2 * ind + 2, mid + 1, high, l, r);
		return {max(left.ff, right.ff), min(left.ss, right.ss)};
	}

	void update(int ind, int low, int high, int l, int r,
	            int val) {
		if (lazy[ind] != 0) {
			seg[ind].ff += lazy[ind];
			seg[ind].ss += lazy[ind];
			if (low != high) {
				lazy[2 * ind + 1] += lazy[ind];
				lazy[2 * ind + 2] += lazy[ind];
			}
			lazy[ind] = 0;
		}

		if (high < l or r < low) return;
		if (low >= l && high <= r) {
			seg[ind].ff += val;
			seg[ind].ss += val;
			if (low != high) {
				lazy[2 * ind + 1] += val;
				lazy[2 * ind + 2] += val;
			}
			return;
		}

		int mid = low + (high - low) / 2;
		update(2 * ind + 1, low, mid, l, r, val);
		update(2 * ind + 2, mid + 1, high, l, r, val);

		seg[ind].ff = max(seg[2 * ind + 1].ff, seg[2 * ind + 2].ff);
		seg[ind].ss = min(seg[2 * ind + 1].ss, seg[2 * ind + 2].ss);
	}
};

int solve(int r, int l) {
	int ans = (l - r) + 1;
	if (r <= 0 && 0 <= l) {}
	else ans++;
	return ans;
}

int solve(int l1, int r1, int l2, int r2) {
	if ((l1 <= r2 && r2 <= r1) || (l2 <= r1 && r1 <= r2)) return solve(min(l1, l2), max(r1, r2));
	else if ((l1 <= l2 && l2 <= r1) || (l2 <= l1 && l1 <= r2)) return solve(min(l1, l2), max(r1, r2));
	else if (l1 - r2 == 1) return solve(l2, r1);
	else if (l2 - r1 == 1) return solve(l1, r2);

	int ans1 = (r1 - l1) + 1, ans2 = (r2 - l2) + 1, zero = 0;
	if (l1 <= 0 && 0 <= r1) {}
	else zero = 1;

	if (l2 <= 0 && 0 <= r2) {}
	else zero = max(zero, 1 * 1ll);

	return ans1 + ans2 + zero;
}

void blackout_yash() {
	/*-------__👌Never Give Up👌__-------*/
	/*----__🤭🤭Stop Stalking🤭🤭__----*/


	int n, t; string s;
	cin >> n >> t >> s;

	vector <int> arr;
	int temp = 0;
	for (auto x : s) {
		if (x == '-') temp--;
		else temp++;
		arr.pb(temp);
	}

	LSGTree ans(n);
	ans.build(0, 0, n - 1, arr);

	while (t--) {
		int l, r;
		cin >> l >> r;
		l--; r--;

		if (!l) {
			if (r + 1 >= n) cout << 1;
			else {
				ans.update(0, 0, n - 1, r + 1, n - 1, -arr[r]);
				pair<int, int> p = ans.query(0, 0, n - 1, r + 1, n - 1);
				cout << solve(p.ss, p.ff);
				ans.update(0, 0, n - 1, r + 1, n - 1, arr[r]);
			}
		} else if (r + 1 == n) {
			if (0 > l - 1) cout << 1;
			else {
				pair<int, int> p = ans.query(0, 0, n - 1, 0, l - 1);
				cout << solve(p.ss, p.ff);
			}
		} else {
			pair<int, int> p1 = ans.query(0, 0, n - 1, 0, l - 1);
			ans.update(0, 0, n - 1, r + 1, n - 1, -(arr[r] - arr[l - 1]));
			pair<int, int> p2 = ans.query(0, 0, n - 1, r + 1, n - 1);
			ans.update(0, 0, n - 1, r + 1, n - 1, (arr[r] - arr[l - 1]));

			cout << solve(p1.ss, p1.ff, p2.ss, p2.ff);
		} cout << nline;
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
	cin >> _;
	while (_--) {blackout_yash();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}