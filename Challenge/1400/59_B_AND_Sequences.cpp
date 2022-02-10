// B. AND Sequences
// Link - https://codeforces.com/problemset/problem/1513/B



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

int fact(int n) {
	int ans = 1;
	fora(i, 1, n + 1) ans = (ans * i) % MOD;
	return ans;
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
		int n, even = 0, odd = 0, zero = 0;
		cin >> n;
		map <int, int> m;
		vector <int> arr(n);
		fora(i, 0, n) {
			cin >> arr[i];
			m[arr[i]]++;
			if (arr[i]) {
				if (arr[i] & 1) odd++;
				else even++;
			} else zero++;
		}

		if (size(m) == 1) cout << fact(n) << nline;
		else if (zero) cout << (((zero * (zero - 1)) % MOD) * fact(n - 2)) % MOD << nline;
		else {
			int key = m.begin()->ff, min = m.begin()->ss, flag = 1;
			for (auto x : arr) {
				if ((x & key) == key) continue;
				flag = 0; break;
			}
			if (flag) cout << (((min * (min - 1)) % MOD) * fact(n - 2)) % MOD << nline;
			else cout << "0\n";
		}
	}

	return 0;
}