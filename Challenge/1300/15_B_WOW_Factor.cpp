// B. WOW Factor
// Link - https://codeforces.com/problemset/problem/1178/B



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


	string s;
	cin >> s;
	if (s.back() != 'v') s.pb('v');
	if (s.front() != 'v') s = "v" + s;

	vector <int> arr;
	int vcount = 0, ocount = 0, n = size(s);
	fora(i, 0, n) {
		if (s[i] == 'v') {
			if (ocount) {
				arr.pb(ocount);
				ocount = 0;
			} vcount++;
			if (i + 1 == n) arr.pb(vcount);
		} else if (s[i] == 'o') {
			if (vcount) {
				arr.pb(vcount);
				vcount = 0;
			} ocount++;
		}
	}

	if (size(arr) < 3) cout << "0\n";
	else {
		int v = 0, ans = 0, store = 0;
		for (int i = size(arr) - 2; i >= 1; i -= 2) {
			v += (arr[i + 1] - 1);
			ans += ((arr[i - 1] - 1) * (arr[i] * v + store));
			store += arr[i] * v;
		} cout << ans << nline;
	}

	return 0;
}