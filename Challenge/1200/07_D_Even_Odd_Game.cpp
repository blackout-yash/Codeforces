// D. Even-Odd Game
// Link - https://codeforces.com/problemset/problem/1472/D



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



	int tt;
	cin >> tt;
	while (tt--) {
		int n, x;
		cin >> n;
		vector <int> odd, even;
		fora(i, 0, n) {
			cin >> x;
			if (x & 1) odd.pb(x);
			else even.pb(x);
		} sort(all(odd)); sort(all(even));

		int i = size(even) - 1, j = size(odd) - 1, alice = 0, bob = 0;
		if (odd.empty()) j = -1;
		if (even.empty()) i = -1;

		fora(k, 0, n) {
			debug(i) debug(j)
			if (i != -1 && j != -1) {
				if (k & 1) {
					if (even[i] < odd[j]) {
						bob += odd[j]; j--;
					} else i--;
				} else {
					if (even[i] > odd[j]) {
						alice += even[i]; i--;
					} else j--;
				}
			} else if (i == -1) {
				if (k & 1) bob += odd[j];
				j--;
			} else {
				if (!(k & 1)) alice += even[i];
				i--;
			}
		}
		if (alice == bob) cout << "Tie\n";
		else if (alice > bob) cout << "Alice\n";
		else cout << "Bob\n";
	}

	return 0;
}