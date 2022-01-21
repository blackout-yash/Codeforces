// C. Equalize
// Link - https://codeforces.com/contest/1037/problem/C



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

int solve(vector <int> &one, vector <int> &zero) {
	map <int, int> m;
	for (auto x : zero) m[x] = 1;

	int ans = 0;
	fora(i, 0, size(one)) {
		if (m[one[i] - 1] == 1) {
			one[i] = m[one[i] - 1] = -1;
			ans++;
		} else if (m[one[i] + 1] == 1) {
			one[i] = m[one[i] + 1] = -1;
			ans++;
		}
	}

	for (auto x : one) (x != -1) ? ans++ : ans;
	for (auto x : m) (x.ss > 0) ? ans++ : ans;

	return ans;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n; string s1, s2;
	cin >> n >> s1 >> s2;

	vector <int> one, zero;
	fora(i, 0, n) {
		if (s1[i] != s2[i]) {
			if (s1[i] == '1') one.pb(i + 1);
			else zero.pb(i + 1);
		}
	}
	if (size(one) > size(zero)) cout << solve(one, zero) << nline;
	else cout << solve(zero, one) << nline;

	return 0;
}