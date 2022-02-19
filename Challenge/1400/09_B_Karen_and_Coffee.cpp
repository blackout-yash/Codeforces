// B. Karen and Coffee
// Link - https://codeforces.com/problemset/problem/816/B



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


	int n, k, q, minimum = mm, maximum = mn;
	cin >> n >> k >> q;
	vector <pair<int, int>> arr(n);
	map <int, int> start, end, temp1, temp2;
	fora(i, 0, n) {
		cin >> arr[i].ff >> arr[i].ss;
		minimum = min(minimum, arr[i].ff);
		maximum = max(maximum, arr[i].ss);
		temp1[arr[i].ff]++;
		temp2[arr[i].ss]++;
	}
	int l = 0, r = 0;
	fora(i, minimum, maximum + 1) {
		if (temp1[i]) l += temp1[i];
		if (temp2[i]) r += temp2[i];

		start[i] = l; end[i + 1] = r;
	}

	vector <int> ans;
	fora(i, minimum, maximum + 1) {
		if (start[i] - end[i] >= k) ans.pb(i);
	}

	while (q--) {
		cin >> l >> r;
		int index1 = lower_bound(all(ans), l) - ans.begin(), index2 = upper_bound(all(ans), r) - ans.begin();
		int size = max(l = 0, index2 - index1);
		cout << size << nline;
	}


	return 0;
}