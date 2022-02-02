// C. Unstable String
// Link - https://codeforces.com/problemset/problem/1535/C



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

vector <int> evenSolve(string &s, int n, char ch) {
	vector <int> arr;
	fora(i, 0, n) {
		if (i & 1) {
			if (s[i] == ch) arr.pb(i);
		} else {
			if (s[i] != ch && s[i] != '?') arr.pb(i);
		}
	} arr.pb(n);
	return arr;
}

vector <int> oddSolve(string &s, int n, char ch) {
	vector <int> arr;
	fora(i, 0, n) {
		if (i & 1) {
			if (s[i] != ch && s[i] != '?') arr.pb(i);
		} else {
			if (s[i] == ch) arr.pb(i);
		}
	} arr.pb(n);
	return arr;
}

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
		int n = size(s), ans = 0;
		vector <int> evenZero = evenSolve(s, n, '0'), evenOne = evenSolve(s, n, '1');
		vector <int> oddZero = oddSolve(s, n, '0'), oddOne = oddSolve(s, n, '1');

		fora(i, 0, n) {
			if (i & 1) {
				int index1 = lower_bound(all(oddZero), i) - oddZero.begin(), index2 = lower_bound(all(oddOne), i) - oddOne.begin();
				ans += max(oddZero[index1], oddOne[index2]) - i;
			} else {
				int index1 = lower_bound(all(evenZero), i) - evenZero.begin(), index2 = lower_bound(all(evenOne), i) - evenOne.begin();
				ans += max(evenZero[index1], evenOne[index2]) - i;
			}
		} cout << ans << nline;
	}

	return 0;
}