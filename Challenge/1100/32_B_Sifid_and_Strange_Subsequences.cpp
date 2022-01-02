// B. Sifid and Strange Subsequences
// Link - https://codeforces.com/problemset/problem/1529/B



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
#define mm INT_MAX
#define mn INT_MIN
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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	fastio();


	int tt;
	cin >> tt;
	while (tt--) {
		int n, x, temp;
		cin >> n;
		vector <int> neg, zero, pos;
		fora(i, 0, n) {
			cin >> x;
			if (!x) zero.pb(x);
			else if (x > 0) pos.pb(x);
			else neg.pb(x);
		} n = size(neg); int z = size(zero), p = size(pos), diff = mm;
		sort(all(neg)); sort(all(pos));
		fora(i, 1, n) diff = min(diff, abs(neg[i] - neg[i - 1]));

		if (z) {
			if (n && p) {
				if (n == 1) {
					if (abs(neg[0]) >= pos[0]) cout << max(n + z, temp = 3) << nline;
					else cout << max(n + z, temp = 2) << nline;
				} else {
					if (diff >= pos[0] && abs(neg[n - 1]) > pos[0]) cout << max(n + z, n + 2) << nline;
					else cout << n + z << nline;
				}
			} else if (n) cout << n + z << nline;
			else if (p) cout << max(z, temp = 2) << nline;
			else cout << z << nline;
		} else {
			if (n && p) {
				if (n == 1) cout << 2 << nline;
				else {
					if (diff >= pos[0]) cout << n + 1 << nline;
					else cout << n << nline;
				}
			} else if (n) cout << n << nline;
			else cout << 1 << nline;
		}

	}

	return 0;
}