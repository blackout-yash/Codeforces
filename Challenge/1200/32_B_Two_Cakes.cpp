// B. Two Cakes
// Link - https://codeforces.com/problemset/problem/911/B



#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define nline "\n"
#define ff first
#define ss second
#define pb push_back
#define pf push_front
#define mp make_pair
#define mm (9*1e18)
#define mn ((-9)*1e18)
#define unsigned int32_t
#define size(x) (x).size()
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007
#define PI 3.141592653589793238462
#define set_bits __builtin_popcountll
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)

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
/*----------------------------------------------------------------------------------------*/


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();


	int n, a, b;
	cin >> n >> a >> b;

	int div, rem, temp = n, prev = 0, ans = 0;
	rfora(i, 1, min(((a + b) / n), min(a, b)) + 1) {
		n = temp;
		map<int, int> m;
		div = a / i; rem = a % i;
		if (div >= n - 1) {
			m[i] = n - 2;
			m[i + rem] = 1;
			n = 1;
		} else {
			m[i] = div - 1;
			m[i + rem] = 1;
			n -= div;
		}

		div = b / i; rem = b % i;
		if (div >= n) {
			m[i] = n - 1;
			m[i + rem] = 1;
			n = 0;
		} else {
			m[i] = div - 1;
			m[i + rem] = 1;
			n -= div;
		}

		if (n == 0) {
			if (m.begin()->ff > prev) {
				ans = i; prev = m.begin()->ff;
			}
		}
	} cout << ans;

	return 0;
}