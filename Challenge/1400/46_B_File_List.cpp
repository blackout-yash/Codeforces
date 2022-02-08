// B. File List
// Link - https://codeforces.com/problemset/problem/174/B



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


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	string s;
	cin >> s;

	vector <string> arr, ans;
	int index = 0, size = 0, flag = 0;
	fora(i, 0, size(s)) {
		if (i && s[i] == s[i - 1] && s[i] == '.') {
			break; flag = 1;
		}
		if (s[i] != '.') size++;
		if (s[i] == '.' || i + 1 == size(s)) {
			arr.pb(s.substr(index, size));
			size = 0; index = i + 1;
		}
	} debug(arr)


	if (s.front() == '.' || s.back() == '.' || size(arr) <= 1 || flag == 1) cout << "NO\n";
	else {
		flag = 0;
		fora(i, 0, size(arr)) {
			if (i == 0) {
				if (size(arr[i]) > 8) {
					flag = 1; break;
				} else ans.pb(arr[i]);
			} else if (i + 1 == size(arr)) {
				if (size(arr[i]) > 3) {
					flag = 1; break;
				} else ans.pb(arr[i]);
			} else {
				int size = size(arr[i]);
				if (size >= 2 && size <= 11) {
					if (size <= 9) {
						ans.pb(arr[i].substr(0, 1));
						ans.pb(arr[i].substr(1, size - 1));
					} else {
						ans.pb(arr[i].substr(0, 3));
						ans.pb(arr[i].substr(3, size - 3));
					}
				} else {
					flag = 1; break;
				}
			}
		}

		if (flag) cout << "NO\n";
		else {
			cout << "YES\n";
			int size = 0;
			for (auto x : ans) {
				cout << x;
				if (size & 1) cout << nline;
				else cout << ".";
				size++;
			}
		}
	}


	return 0;
}