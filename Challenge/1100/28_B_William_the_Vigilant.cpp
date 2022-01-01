// B. William the Vigilant
// Link - https://codeforces.com/problemset/problem/1609/B



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


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	fastio();

	int n, q, count = 0; string s;
	cin >> n >> q >> s;
	vector <int> arr;
	fora(i, 2, n) {
		if (s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a') {
			count++; i += 2;
		}
	}

	int num; char ch;
	while (q--) {
		cin >> num >> ch;
		int max, min;
		if (num + 2 <= n) max = num + 2;
		else max = n;
		if (num - 2 >= 1) min = num - 2;
		else min = 1;

		int temp1 = 0, temp2 = 0; string s1;
		fora(i, min, max + 1) {
			s1.pb(s[i - 1]);
			if (size(s1) == 3) {
				if (s1 == "abc") {
					temp1++; s1.clear();
				} else s1.erase(s1.begin());
			}
		} s1.clear();

		s[num - 1] = ch;
		fora(i, min, max + 1) {
			s1.pb(s[i - 1]);
			if (size(s1) == 3) {
				if (s1 == "abc") {
					temp2++; s1.clear();
				} else s1.erase(s1.begin());
			}
		}
		count += (temp2 - temp1);
		cout << count << nline;
	}

	return 0;
}