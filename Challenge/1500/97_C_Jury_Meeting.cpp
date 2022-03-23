// C. Jury Meeting
// Link - https://codeforces.com/problemset/problem/1569/C



/*--------------------------------------👻 Yash 👻--------------------------------------*/
/*----------------------------------😔 Editorial Op! 😔---------------------------------*/

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
#define MOD 998244353
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
int modAdd(int a, int b, int m = MOD) {a = a % m; b = b % m; return (((a + b) % m) + m) % m;}
int modSub(int a, int b, int m = MOD) {a = a % m; b = b % m; return (((a - b) % m) + m) % m;}
int modMul(int a, int b, int m = MOD) {a = a % m; b = b % m; return (((a * b) % m) + m) % m;}
int solution(int ans, int m = MOD) {return (ans < 0) ? ans + m : ans;}
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
const int n = 3 * 1e5;
vector <int> fact(n);
int factorial() {
	fact[0] = 1;
	fora(i, 1, n + 1) fact[i] = modMul(i, fact[i - 1]);
}

int modInverse(int a, int m = MOD) {
	int m0 = m;
	int y = 0, x = 1;

	if (m == 1) return 0;

	while (a > 1) {
		int q = a / m;
		int t = m;

		m = a % m, a = t;
		t = y;

		y = x - q * y;
		x = t;
	}

	if (x < 0) x += m0;

	return x;
}

int ncr(int n, int r) {
	if (r > n) return 0;
	int num = fact[n], denom = modMul(fact[r], fact[n - r]);
	denom = modInverse(denom);
	return modMul(num, denom);
}

// Link - https://youtu.be/OcJZd-KzJlA?t=616
void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n;
	cin >> n;
	vector <int> arr(n);
	fora(i, 0, n) cin >> arr[i];

	int max = *max_element(all(arr)), count1 = count(all(arr), max), count2 = count(all(arr), max - 1);

	int ans = fact[n];
	if (count1 > 1) cout << ans << nline;
	else if (!count2) cout << count2 << nline;
	else {
		int temp = 0;
		fora(i, 1, n) temp += ncr(i, count2);
		temp = modMul(fact[count2], temp);
		temp = modMul(fact[n - (count2 + 1)], temp);
		cout << solution(ans - temp) << nline;
	}
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	factorial();
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