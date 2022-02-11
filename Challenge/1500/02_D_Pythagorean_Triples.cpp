// D. Pythagorean Triples
// Link - https://codeforces.com/problemset/problem/1487/D



/*--------------------------------------👻 Yash 👻--------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
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

bool check(int i, int n) {
	int low = 1, high = n;
	while (low <= high) {
		int mid = low + (high - low) / 2, temp1 = i * i, temp2 = (2 * mid) + 1;

		if (temp1 == temp2) {
			if (n >= temp1 - mid) return true;
			else high = mid - 1;
		} else if (temp1 > temp2) low = mid + 1;
		else high = mid - 1;
	} return false;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;

		int low = 3, high = n, ans = 0, prev1 = low, prev2 = high;
		while (low < high) {
			int mid = low + (high - low) / 2;
			if (mid & 1) {}
			else mid--;

			if (check(mid, n)) {
				ans = max(ans, mid);
				low = mid + 1;
			} else high = mid - 1;

			if (prev1 == low && prev2 == high) break;
			else {prev1 = low; prev2 = high;}
		} cout << (ans / 2) << nline;

	}

	return 0;
}