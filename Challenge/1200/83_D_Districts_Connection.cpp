// D. Districts Connection
// Link - https://codeforces.com/problemset/problem/1433/D



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


	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector <int> arr(n);
		fora(i, 0, n) cin >> arr[i];

		vector <pair <int, int>> ans;
		fora(i, 0, n - 1) {
			if (arr[i] != arr[i + 1]) ans.pb(mp(i + 1, i + 2));
			else {
				int index = -1;
				fora(j, i + 1, n) {
					if (arr[i] != arr[j]) {
						index = j; break;
					}
				}
				if (index != -1) {
					fora(j, i, index) {
						ans.pb(mp(j + 1, index + 1));
					} if (index) i = index - 1;
				} else {
					fora(j, 0, n) {
						if (arr[i] != arr[j]) index = j + 1;
					}

					debug(index)
					if (index != -1) fora(j, i + 1, n) ans.pb(mp(j + 1, index));
					i = n;
				}
			}
		}

		if (size(ans) == n - 1) {
			cout << "YES\n";
			for (auto x : ans) cout << x.ff << " " << x.ss << nline;
		} else cout << "NO\n";
	}

	return 0;
}