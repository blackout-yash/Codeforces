// A. Exercising Walk
// Link - https://codeforces.com/problemset/problem/1332/A



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

void x1st_4th(int x[], int &left, int &right) {
	left = x[0] - x[1]; right = x[2] - x[0];
}

void x2nd_3rd(int x[], int &left, int &right) {
	right = x[0] - x[1]; left = x[2] - x[0];
}

void y1st_2nd(int y[], int &down, int &up) {
	down = y[0] - y[1]; up = y[2] - y[0];
}

void y3rd_4th(int y[], int &down, int &up) {
	down = y[0] - y[1]; up   = y[2] - y[0];
}



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
		int a, b, c, d, x[3], y[3];
		cin >> a >> b >> c >> d;
		fora(i, 0, 3) cin >> x[i] >> y[i];

		int left = x[0] - x[1], right = x[2] - x[0], down = y[0] - y[1], up = y[2] - y[0], diff1 = abs(a - b), diff2 = abs(c - d);
		a = abs(a); b = abs(b); c = abs(c); d = abs(d);
		bool flag1 = false, flag2 = false;

		if (a || b) {
			if (a > b) {
				if (left && left >= diff1) flag1 = true;
			} else if (a < b) {
				if (right && right >= diff1) flag1 = true;
			} else if ((left && left >= diff1) || (right && right >= diff1)) flag1 = true;
		} else flag1 = true;

		if (c || d) {
			if (c > d) {
				if (down && down >= diff2) flag2 = true;
			} else if (c < d) {
				if (up && up >= diff2) flag2 = true;
			} else if ((down && down >= diff2) || (up && up >= diff2)) flag2 = true;
		} else flag2 = true;

		if (flag1 && flag2) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}