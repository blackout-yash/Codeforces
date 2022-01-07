// B. Vitamins
// Link - https://codeforces.com/problemset/problem/1042/B



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
	map<string, int> m;
	while (tt--) {
		int n; string s;
		cin >> n >> s;
		sort(all(s));
		if (m.count(s)) m[s] = min(m[s], n);
		else m[s] = n;
	}

	string s1 = "A", s2 = "B", s3 = "C", s4 = "AB", s5 = "AC", s6 = "BC", s7 = "ABC";
	int minimum = mm;
	if (m.count(s1) && m.count(s2) && m.count(s3)) minimum = min(minimum, m[s1] + m[s2] + m[s3]);

	if (m.count(s1) && m.count(s6)) minimum = min(minimum, m[s1] + m[s6]);
	if (m.count(s2) && m.count(s5)) minimum = min(minimum, m[s2] + m[s5]);
	if (m.count(s3) && m.count(s4)) minimum = min(minimum, m[s3] + m[s4]);

	if (m.count(s4) && m.count(s5)) minimum = min(minimum, m[s4] + m[s5]);
	if (m.count(s4) && m.count(s6)) minimum = min(minimum, m[s4] + m[s6]);
	if (m.count(s5) && m.count(s6)) minimum = min(minimum, m[s5] + m[s6]);

	if (m.count(s7)) minimum = min(minimum, m[s7]);

	if (minimum == mm) cout << "-1";
	else cout << minimum;

	return 0;
}