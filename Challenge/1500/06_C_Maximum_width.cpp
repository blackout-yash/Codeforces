// C. Maximum width
// Link - https://codeforces.com/contest/1492/problem/C



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


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n, m; string s1, s2;
	cin >> n >> m >> s1 >> s2;

	vector <vector <int>> storage(26);
	fora(i, 0, n) {
		int ch = unsigned(s1[i] - 'a');
		storage[ch].pb(i);
	}

	vector <int> start(m), end(m);
	int j = 0, ans = 0;
	fora(i, 0, n) {
		if (s1[i] == s2[j]) {
			start[j] = i; j++;
		}
	} j = size(s2) - 1;
	rfora(i, 0, n) {
		if (s1[i] == s2[j]) {
			end[j] = i; j--;
		}
	} end.pb(n);

	fora(i, 1, m) {
		int temp = end[i + 1], ch = unsigned(s2[i] - 'a');
		int index = lower_bound(all(storage[ch]), temp) - storage[ch].begin();
		if (size(storage[ch]) <= index || storage[ch][index] >= temp) index--;
		ans = max(ans, storage[ch][index] - start[i - 1]);
	} cout << ans;

	return 0;
}