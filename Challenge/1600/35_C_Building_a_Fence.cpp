// C. Building a Fence
// Link - https://codeforces.com/contest/1469/problem/C



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

bool check (vector <pair<int, int>> &arr) {
	fora(i, 0, size(arr) - 1) {
		if (arr[i] == arr[i + 1]) {}
		else if (arr[i].ff < arr[i + 1].ff && arr[i].ss > arr[i + 1].ff) {}
		else if (arr[i].ff < arr[i + 1].ss && arr[i].ss > arr[i + 1].ss) {}
		else {
			debug(i)
			return false;
		}
	} return true;
}

int solve(int a, int b, int h, int k) {
	int max1 = max(a, b) + 1, max2 = h + k + (k - 1), ans = -1;

	if (max1 > max2) {}
	else {
		int req = (max1 - k) - h;
		req = max(req, 1ll * 0);
		ans = h + req;
	} return ans;
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n, k;
	cin >> n >> k;

	vector <int> h(n);
	vector <pair<int, int>> arr(n, { -1, -1}), store;
	fora(i, 0, n) {
		cin >> h[i];
		if (!i || i + 1 == n) continue;
		store.pb({h[i], i});
	} sort(all(store));

	arr[0] = {h[0], h[0] + k};
	arr[n - 1] = {h[n - 1], h[n - 1] + k};
	int flag = 1;
	if (n > 2) {
		rfora(i, 0, size(store)) {
			int index = store[i].ss;
			if (h[index - 1] <= h[index] && h[index] >= h[index + 1]) {
				arr[index].ff = h[index];
				arr[index].ss = h[index] + k;
			} else {
				int start = mm, temp = solve(arr[index - 1].ff, arr[index + 1].ff, h[index], k);
				if (start > temp && temp != -1) start = temp;
				temp = solve(arr[index - 1].ff, arr[index + 1].ss, h[index], k);
				if (start > temp && temp != -1) start = temp;
				temp = solve(arr[index - 1].ss, arr[index + 1].ff, h[index], k);
				if (start > temp && temp != -1) start = temp;
				temp = solve(arr[index - 1].ss, arr[index + 1].ss, h[index], k);
				if (start > temp && temp != -1) start = temp;

				if (start == mm) {
					flag = 0; break;
				} else {
					arr[index].ff = start;
					arr[index].ss = start + k;
				}
			}
		}
	} else {
		if (abs(h[0] - h[1]) >= k) flag = 0;
	}

	if (flag) {
		if (check(arr)) cout << "YES\n";
		else cout << "NO\n";
	} else cout << "NO\n";
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