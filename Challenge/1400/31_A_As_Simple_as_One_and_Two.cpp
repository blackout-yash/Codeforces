// A. As Simple as One and Two
// Link - https://codeforces.com/problemset/problem/1276/A



/*--------------------------------------👻 Yash 👻--------------------------------------*/
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
	/*-------👌Never Give Up👌-------*/


	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;

		int n = size(s);
		if (n <= 2) cout << "0\n\n";
		else {
			vector <int> arr;
			rfora(i, 0, size(s) - 2) {
				if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e') {
					if (i) {
						if (s[i] == s[i - 1]) {
							arr.pb(i + 2);
							s[i + 1] = '*';
						} else {
							arr.pb(i + 1);
							s[i] = '*';
						}
					} else {
						arr.pb(i + 1);
						s[i] = '*';
					}
				} else if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o') {
					if (i) {
						if (s[i] == s[i - 1]) {
							arr.pb(i + 2);
							s[i + 1] = '*';
						} else {
							arr.pb(i + 1);
							s[i] = '*';
						}
					} else {
						arr.pb(i + 1);
						s[i] = '*';
					}
				}
			}
			cout << size(arr) << nline;
			for (auto x : arr) cout << x << " ";
			cout << nline;
		}
	}

	return 0;
}