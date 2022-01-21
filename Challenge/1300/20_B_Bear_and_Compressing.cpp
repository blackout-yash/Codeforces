// B. Bear and Compressing
// Link - https://codeforces.com/problemset/problem/653/B



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
char solve(vector <pair <string, char>> &arr, string &s) {
	for (auto x : arr) {
		if (x.ff == s) return x.ss;
	} return '*';
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n, q;
	cin >> n >> q;
	vector <pair <string, char>> arr(q);
	fora(i, 0, q) cin >> arr[i].ff >> arr[i].ss;

	set <string> s;
	fora(i, 0, q) {
		string temp = arr[i].ff;
		fora(j, 0, 6) {
			temp.pb('a' + j);
			fora(k, 0, 6) {
				temp.pb('a' + k);
				fora(l, 0, 6) {
					temp.pb('a' + l);
					fora(m, 0, 6) {
						temp.pb('a' + m);
						s.insert(temp.substr(0, n));
						temp.pop_back();
					} temp.pop_back();
				} temp.pop_back();
			} temp.pop_back();
		}
	}

	int count = 0;
	for (auto x : s) {
		char temp = x[0]; string s;
		fora(i, 0, n - 1) {
			string s;
			s.pb(temp); s.pb(x[i + 1]);

			temp = solve(arr, s);
			if (temp == '*') break;
		} if (temp == 'a')count++;
	} cout << count;

	return 0;
}