// C. Two Arrays
// Link - https://codeforces.com/problemset/problem/1288/C



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
int modAdd(int a, int b, int m = MOD) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int modSub(int a, int b, int m = MOD) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int modMul(int a, int b, int m = MOD) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int solution(int ans, int m = MOD) {return (ans < 0) ? ans + m : ans;}

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

// Go through mod value once
int gcdExtended(int a, int b, int *x, int *y) {
	if (a == 0) {
		*x = 0, *y = 1;
		return b;
	}

	int x1, y1;
	int gcd = gcdExtended(b % a, a, &x1, &y1);

	*x = y1 - (b / a) * x1;
	*y = x1;

	return gcd;
}

int modInverse(int b, int m = MOD) {
	int x, y;
	int g = gcdExtended(b, m, &x, &y);

	if (g != 1) return -1;
	return (x % m + m) % m;
}

int modDivide(int a, int b, int m = MOD) {
	a = a % m;
	int inv = modInverse(b, m);

	if (inv == -1) return -1;
	return (inv * a) % m;
}

int solve(int n) {
	int ans = 1;
	fora(i, 1, n + 1) ans = modMul(ans, i);
	return ans;
}

// No of permutation in sorted order of size p from total n numbers = (n - 1 + p)! / (p!) * (n - 1)!

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n, m;
	cin >> n >> m;

	int ans1 = solve(n - 1 + (2 * m)), ans2 = solve(2 * m), ans3 = solve(n - 1), ans4 = modMul(ans2, ans3);

	cout << solution(modDivide(ans1, ans4));
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