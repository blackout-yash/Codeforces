// B. Blocks
// Link - https://codeforces.com/problemset/problem/1271/B



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

vector <int> solve(string &s, char ch, int n) {
	vector <int> ans;
	fora(i, 0, n - 1) {
		if (s[i] == ch) {}
		else {
			ans.pb(i + 1);
			(s[i] == 'B') ? s[i] = 'W' : s[i] = 'B';
			(s[i + 1] == 'B') ? s[i + 1] = 'W' : s[i + 1] = 'B';
		}
	} return ans;
}

bool check(string &s, int n) {
	char ch = s.front();
	fora(i, 0, n) {
		if (s[i] != ch) return false;
	} return true;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n; string s;
	cin >> n >> s;

	string temp1 = s, temp2 = s;
	vector <int> ans1 = solve(temp1, 'W', n), ans2 = solve(temp2, 'B', n);

	if (check(temp1, n)) {
		cout << size(ans1) << nline;
		for (auto x : ans1) cout << x << " ";
		cout << nline;
	} else if (check(temp2, n)) {
		cout << size(ans2) << nline;
		for (auto x : ans2) cout << x << " ";
		cout << nline;
	} else cout << "-1\n";

	return 0;
}