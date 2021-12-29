// B. Nezzar and Lucky Number
// Link - https://codeforces.com/problemset/problem/1478/B



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

bool solve(string &s, char c) {
	fora(i, 0, size(s)) {
		if (s[i] == c) return true;
	} return false;
}

bool check(int num, int d) {
	int temp = num; char ch = char(d + '0');
	while (true) {
		string s = to_string(temp);
		if (solve(s, ch)) return true;
		temp -= d;
		if (temp < 0) break;
	}

	fora(i, 0, 11) {
		temp = num - (d * (i * 10));
		string s = to_string(temp);
		if (temp < 0) return false;
		else if (solve(s, ch)) return true;
	} return false;
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
		int n, d, num;
		cin >> n >> d;
		while (n--) {
			cin >> num;
			int size = floor(log10(num) + 1);
			if (size >= 3) cout << "YES\n";
			else {
				if (d > num) cout << "NO\n";
				else if (num % d == 0) cout << "YES\n";
				else if (check(num, d)) cout << "YES\n";
				else cout << "NO\n";
			}
		}
	}

	return 0;
}