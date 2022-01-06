// B. Restricted RPS
// Link - https://codeforces.com/problemset/problem/1245/B



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
		int n, r, p, s; string str;
		cin >> n >> r >> p >> s >> str;

		vector <int> rock(n), paper(n), scissors(n);
		rfora(i, 0, n) {
			if (str[i] == 'R') rock[i] = 1;
			if (i + 1 != n) rock[i] += rock[i + 1];
		}
		rfora(i, 0, n) {
			if (str[i] == 'P') paper[i] = 1;
			if (i + 1 != n) paper[i] += paper[i + 1];
		}
		rfora(i, 0, n) {
			if (str[i] == 'S') scissors[i] = 1;
			if (i + 1 != n) scissors[i] += scissors[i + 1];
		}

		vector <char> store(n);
		int ans = 0, range = n / 2;
		if (n & 1) range++;
		fora(i, 0, n) {
			if (str[i] == 'S') {
				if (r) {
					store[i] = 'R';
					r--; ans++;
				} else if (p && p > rock[i]) {p--; store[i] = 'P';}
				else if (s) {s--; store[i] = 'S';}
				else {p--; store[i] = 'P';}
			} else if (str[i] == 'R') {
				if (p) {
					store[i] = 'P';
					p--; ans++;
				} else if (s && s > paper[i]) {s--; store[i] = 'S';}
				else if (r) {r--; store[i] = 'R';}
				else {s--; store[i] = 'S';}
			} else {
				if (s) {
					store[i] = 'S';
					s--; ans++;
				} else if (r && r > scissors[i]) {r--; store[i] = 'R';}
				else if (p) {p--; store[i] = 'P';}
				else {r--; store[i] = 'R';}
			}
		}
		if (ans >= range) {
			cout << "YES\n";
			for (auto x : store) cout << x;
			cout << nline;
		} else cout << "NO\n";
	}

	return 0;
}