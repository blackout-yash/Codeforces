// B. Cards
// Link - https://codeforces.com/problemset/problem/626/B



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


	int n; string s;
	cin >> n >> s;

	int b = 0, g = 0, r = 0;
	fora(i, 0, n) {
		if (s[i] == 'B') b++;
		else if (s[i] == 'G') g++;
		else r++;
	}

	bool flag1 = false, flag2 = false, flag3 = false;
	if (b) {
		if ((!g && !r) || (g && r)) flag1 = true;
		else if (!g && r > 1) flag1 = true;
		else if (!r && g > 1) flag1 = true;
	} else {
		if (g && r) flag1 = true;
	}

	if (g) {
		if ((!b && !r) || (b && r)) flag2 = true;
		else if (!b && r > 1) flag2 = true;
		else if (!r && b > 1) flag2 = true;
	} else {
		if (b && r) flag2 = true;
	}

	if (r) {
		if ((!b && !g) || (b && g)) flag3 = true;
		else if (!b && g > 1) flag3 = true;
		else if (!g && b > 1) flag3 = true;
	} else {
		if (b && g) flag3 = true;
	}

	if (flag1) cout << "B";
	if (flag2) cout << "G";
	if (flag3) cout << "R";

	return 0;
}