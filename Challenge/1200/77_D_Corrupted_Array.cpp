// D. Corrupted Array
// Link - https://codeforces.com/contest/1512/problem/D



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
		vector <int> arr(n + 2);
		fora(i, 0, n + 2) cin >> arr[i];
		sort(all(arr));

		int sum = 0, a, b;
		fora(i, 0, n + 2) {
			if (i == n && arr[i] == sum) {
				a = arr[i];
				b = arr[i + 1];
				break;
			} else if (i == n + 1) {
				a = arr[i];
				b = sum - arr[i];
				int index = lower_bound(all(arr), b) - arr.begin();
				if (!binary_search(all(arr), b)) a = b = -1;
				else if (index == i) a = b = -1;
			} else sum += arr[i];
		} debug(mp(a, b))

		if (a == -1 && b == -1) cout << a << nline;
		else {
			bool flag1 = true, flag2 = true;
			for (auto x : arr) {
				if (x == a && flag1) {
					flag1 = false;
				} else if (x == b && flag2) {
					flag2 = false;
				} else cout << x << " ";
			} cout << nline;
		}
	}

	return 0;
}