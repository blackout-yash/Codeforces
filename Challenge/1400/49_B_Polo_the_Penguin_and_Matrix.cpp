// B. Polo the Penguin and Matrix
// Link - https://codeforces.com/problemset/problem/289/B



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


	int n, m, d;
	cin >> n >> m >> d;

	vector <int> arr(n * m), sum(n * m);
	set <int> s;
	fora(i, 0, n * m) {
		cin >> arr[i];
		s.insert(arr[i]);
	} sort(all(arr));

	fora(i, 0, n * m) {
		if (i) sum[i] = sum[i - 1] + arr[i];
		else sum[i] = arr[i];
	}

	int ans = mm, size = n * m;
	for (auto x : s) {
		int index1 = lower_bound(all(arr), x) - arr.begin(), index2 = upper_bound(all(arr), x) - arr.begin();
		int sum1 = 0, sum2 = 0, sum3 = index1 * x, sum4 = (size - index2) * x;

		if (index1 - 1 >= 0) sum1 = sum[index1 - 1];
		if (index2 - 1 >= 0) sum2 = sum.back() - sum[index2 - 1];

		int req1 = sum3 - sum1, req2 = sum2 - sum4;
		if (req1 % d || req2 % d) {}
		else ans = min(ans, (req1 / d) + (req2 / d));
	}(ans == mm) ? cout << -1 : cout << ans;

	return 0;
}