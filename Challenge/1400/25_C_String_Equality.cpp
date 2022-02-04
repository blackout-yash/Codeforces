// C. String Equality
// Link - https://codeforces.com/problemset/problem/1451/C



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


	int tt;
	cin >> tt;
	while (tt--) {
		int n, k, flag = 1; string s1, s2;
		cin >> n >> k >> s1 >> s2;

		map <char, int> a, b;
		fora(i, 0, n) a[s1[i]]++;
		fora(i, 0, n) b[s2[i]]++;

		vector <pair<char, int>> arr1, arr2;
		for (auto x : a) arr1.pb(mp(x.ff, x.ss));
		for (auto x : b) arr2.pb(mp(x.ff, x.ss));

		fora(i, 0, size(arr1)) {
			fora(j, 0, size(arr2)) {
				if (arr1[i].ff == arr2[j].ff) {
					if (arr2[j].ss >= arr1[i].ss) {
						arr2[j].ss -= arr1[i].ss;
						arr1[i].ss = 0;
					} else {
						arr1[i].ss -= arr2[j].ss;
						arr2[j].ss = 0;
					}
				}
			} if (arr1[i].ss % k) flag = 0;
		}

		if (flag) {
			fora(i, 0, size(arr1)) {
				if (arr1[i].ss) {
					fora(j, 0, size(arr2)) {
						if (arr2[j].ff > arr1[i].ff && arr2[j].ss >= k) {
							int temp1 = arr2[j].ss / k, temp2 = arr1[i].ss / k;

							if (temp1 >= temp2) {
								arr2[j].ss -= arr1[i].ss;
								arr1[i].ss = 0;
							} else {
								arr1[i].ss -= (temp1 * k);
								arr2[j].ss -= (temp1 * k);
							}
						}
					}
				} if (arr1[i].ss) {
					flag = 0; break;
				}
			}

			if (flag) cout << "YES\n";
			else cout << "NO\n";
		} else cout << "NO\n";

	}

	return 0;
}