// C. Minimize Distance
// Link - https://codeforces.com/contest/1585



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
		int n, k, psum = 0, ptemp = 0, nsum = 0, ntemp = 0, range = 0, maximum = 0, flag = 1;
		cin >> n >> k;
		vector <int> positive, negative;
		fora(i, 0, n) {
			int x; cin >> x;
			if (x) {
				if (x > 0) positive.pb(x);
				else negative.pb((-1)*x);
			}
		} sort(all(positive));
		sort(all(negative));

		if (positive.empty()) {}
		else {
			rfora(i, 0, size(positive)) {
				range++; maximum = max(maximum, positive[i]);
				if (i == 0 || range == k) {
					psum += (2 * maximum);
					if (flag) {
						psum -= maximum;
						ptemp = maximum;
						flag = 0;
					} maximum = range = 0;
				}
			}
		}

		if (negative.empty()) {}
		else {
			flag = 1;
			rfora(i, 0, size(negative)) {
				range++; maximum = max(maximum, negative[i]);
				if (i == 0 || range == k) {
					nsum += (2 * maximum);
					if (flag) {
						nsum -= maximum;
						ntemp = maximum;
						flag = 0;
					} maximum = range = 0;
				}
			}
		} cout << (psum + nsum) + min(ptemp, ntemp) << nline;
	}

	return 0;
}