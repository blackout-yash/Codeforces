// C. Given Length and Sum of Digits...
// Link - https://codeforces.com/contest/489/problem/C



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

	int n, sum, flag1 = 1, flag2 = 1;
	cin >> n >> sum;

	if (n == 1 && sum == 0) cout << "0\n0";
	else {
		vector <int> ans1, ans2;
		int temp1 = sum, temp2 = sum;
		fora(i, 0, n) {
			if (temp1) {
				if (i + 1 == n) {
					if (temp1 <= 9) ans1.pb(temp1);
					else flag1 = 0;
				} else if (temp1 == 1) ans1.pb(0);
				else if (temp1 > 9) {
					ans1.pb(9);
					temp1 -= 9;
				} else {
					ans1.pb(temp1 - 1);
					temp1 = 1;
				}
			} else {
				flag1 = 0;
				break;
			}
		}

		if (temp2 == 0 || 9 * n < sum) flag2 = 0;
		else {
			fora(i, 0, n) {
				if (temp2 >= 9) {
					ans2.pb(9);
					temp2 -= 9;
				} else {
					ans2.pb(temp2);
					temp2 = 0;
				}
			}
		}

		if (flag1) {
			rfora(i, 0, n) cout << ans1[i];
			cout << nline;
		} else cout << "-1\n";

		if (flag2) {
			for (auto x : ans2) cout << x;
		} else cout << -1;
	}
	return 0;
}