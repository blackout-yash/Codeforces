// C. A-B Palindrome
// Link - https://codeforces.com/problemset/problem/1512/C



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

int count(string &s, char ch) {
	int count = 0;
	for (auto x : s) {
		if (x == ch) count++;
	} return count;
}

bool isPalidrome(string &s) {
	int l = 0, r = size(s) - 1;
	while (l <= r) {
		if (s[l] != s[r]) return false;
		l++; r--;
	} return true;
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
		int a, b; string s;
		cin >> a >> b >> s;

		int n = size(s), l = 0, r = n - 1;
		while (l < r) {
			if (s[l] == '?' && s[r] == '?') {}
			else if (s[l] == '?') s[l] = (s[r] == '1') ? '1' : '0';
			else if (s[r] == '?') s[r] = (s[l] == '1') ? '1' : '0';
			l++; r--;
		}

		int temp1 = count(s, '0'), temp2 = count(s, '1');
		if (a > temp1) {
			l = 0; r = n - 1;
			while (l <= r) {
				if (temp1 == a) break;
				else if (a - temp1 == 1) {
					if (l == r && s[l] == '?') {
						s[l] = '0'; temp1++;
					}
				} else if (l != r && s[l] == '?' && s[r] == '?') {
					s[l] = s[r] = '0'; temp1 += 2;
				} l++; r--;
			}
		}

		if (b > temp2) {
			l = 0; r = n - 1;
			while (l <= r) {
				if (temp2 == b) break;
				else if (b - temp2 == 1) {
					if (l == r && s[l] == '?') {
						s[l] = '1'; temp2++;
					}
				} else if (l != r && s[l] == '?' && s[r] == '?') {
					s[l] = s[r] = '1'; temp2 += 2;
				} l++; r--;
			}
		}

		if (a == count(s, '0') && b == count(s, '1') && isPalidrome(s)) cout << s << nline;
		else cout << "-1\n";
	}

	return 0;
}