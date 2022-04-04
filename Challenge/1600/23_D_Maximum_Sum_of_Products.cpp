// D. Maximum Sum of Products
// Link - https://codeforces.com/problemset/problem/1519/D



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

bool isValid(int n, int l, int r) {
	if (l >= 0 && l <= n && r >= 0 && r <= n) return true;
	return false;
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n;
	cin >> n;
	vector <int> a(n + 1), b(n + 1), sum(n + 1);
	fora(i, 1, n + 1) cin >> a[i];
	fora(i, 1, n + 1) cin >> b[i];

	rfora(i, 1, n + 1) {
		sum[i] = a[i] * b[i];
		if (i + 1 <= n) sum[i] += sum[i + 1];
	}

	vector <vector<int>> m(n + 1, vector<int> (n + 1, -1));
	fora(i, 0, n + 1) {
		rfora(j, i, n + 1) {
			int l = i - 1, r = j + 1;

			if (isValid(n, l, r) && m[l][r] != -1) m[i][j] = m[l][r] - ((a[r] * b[l]) + (a[l] * b[r]));
			else {
				int pro = 0, l = j;
				fora(k, i, j + 1) {
					pro += (a[k] * b[l]);
					l--;
				} m[i][j] = pro;
			}
		}
	}

	int ans = sum[1], curr = 0;
	fora(i, 0, n + 1) {
		curr += (a[i] * b[i]);
		fora(j, i + 1, n + 1) {
			int mid = m[i + 1][j], back = 0;
			if (j + 1 <= n) back = sum[j + 1];
			ans = max(ans, curr + mid + back);
		}
	} cout << ans << nline;
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