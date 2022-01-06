// B. Maximum Product
// Link - https://codeforces.com/problemset/problem/1406/B



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


	int tt;
	cin >> tt;
	while (tt--) {
		int n, neg = 0, zero = 0, pos = 0;
		cin >> n;
		vector <int> arr(n);
		fora(i, 0, n) {
			cin >> arr[i];
			if (!arr[i]) zero++;
			else if (arr[i] > 0) pos++;
			else neg++;
		} sort(all(arr));

		int temp1 = arr[n - 3] * arr[n - 2] * arr[n - 1], temp2 = arr[n - 5] * arr[n - 4] * temp1;
		int temp3 = arr[0] * arr[1], temp4 = temp3 * arr[2] * arr[3], temp5 = 1;
		int count = 5;
		rfora(i, 0, n) {
			if (arr[i] < 0) {
				temp5 *= arr[i];
				count--;
			}
			if (!count) break;
		}

		if (pos == n) cout << temp2 << nline;
		else if (neg == n) cout << temp5 << nline;
		else if (zero == n) cout << "0\n";
		else {
			int max1 = (-9 * 1e18), max2 = max1;

			if (neg >= 2) max1 = temp1 * temp3;
			if (neg >= 4) max2 = temp4 * arr[n - 1];

			cout << max(max1, max(max2, temp2)) << nline;
		}
	}
	return 0;
}