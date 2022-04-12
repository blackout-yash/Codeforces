// E. Robot on the Board 1
// Link - https://codeforces.com/problemset/problem/1607/E



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

bool solve(int x, int m, int xmin, int xmax) {
	int temp1 = x + xmin, temp2 = x + xmax;
	if (1 <= temp1 && temp1 <= m && 1 <= temp2 && temp2 <= m) return true;
	return false;
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n, m; string s;
	cin >> n >> m >> s;

	int x = 1, y = 1, xtemp = 0, ytemp = 0, xmin = 0, xmax = 0, ymax = 0, ymin = 0;
	for (auto z : s) {
		if (z == 'R') ytemp++;
		else if (z == 'L') ytemp--;
		else if (z == 'D') xtemp++;
		else xtemp--;

		int temp1 = x + xtemp, temp2 = y + ytemp;
		if (1 <= temp1 && temp1 <= n) {}
		else {
			if (temp1 < 1) {
				x++;
				if (solve(x, n, xmin, xmax)) {}
				else {x--; break;}
			}
			if (temp1 > n) {
				x--;
				if (solve(x, n, xmin, xmax)) {}
				else {x++; break;}
			}
		}

		if (1 <= temp2 && temp2 <= m) {}
		else {
			if (temp2 < 1) {
				y++;
				if (solve(y, m, ymin, ymax)) {}
				else {y--; break;}
			}
			if (temp2 > m) {
				y--;
				if (solve(y, m, ymin, ymax)) {}
				else {y++; break;}
			}
		}

		xmax = max(xmax, xtemp);
		xmin = min(xmin, xtemp);

		ymax = max(ymax, ytemp);
		ymin = min(ymin, ytemp);
	} cout << x << " " << y << nline;
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