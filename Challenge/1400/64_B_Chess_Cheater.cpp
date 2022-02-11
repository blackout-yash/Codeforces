// B. Chess Cheater
// Link - codeforces.com/problemset/problem/1427/B



/*--------------------------------------👻 Yash 👻--------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
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
		int n, k; string s;
		cin >> n >> k >> s;

		vector <pair<int, int>> arr, store;
		int index, size = 0;
		fora(i, 0, n) {
			if (s[i] == 'L') {
				size++;
				if (size == 1) index = i;
			}

			if (size) {
				if (i + 1 == n || s[i] == 'W') {
					if (index == 0 || (i + 1 == n && s[i] == 'L')) store.pb({size, index});
					else arr.pb({size, index});
					size = 0;
				}
			}
		} sort(all(arr));
		sort(all(store));

		fora(i, 0, size(arr)) {
			fora(j, arr[i].ss, n) {
				if (s[j] == 'W' || k == 0) break;
				s[j] = 'W'; k--;
			} if (k == 0) break;
		}

		if (k) {
			fora(i, 0, size(store)) {
				if (store[i].ss) {
					fora(j, store[i].ss, n) {
						if (s[j] == 'W' || k == 0) break;
						s[j] = 'W'; k--;
					}
				} else {
					rfora(j, 0, store[i].ff) {
						if (k == 0) break;
						s[j] = 'W'; k--;
					}
				}
			}
		}

		int ans = 0;
		fora(i, 0, n) {
			if (i) {
				if (s[i] == 'W') {
					if (s[i - 1] == 'W') ans += 2;
					else ans++;
				}
			} else if (s[i] == 'W') ans++;
		} cout << ans << nline;
	}

	return 0;
}