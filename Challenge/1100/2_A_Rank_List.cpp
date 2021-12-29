// A. Rank List
// Link - https://codeforces.com/problemset/problem/166/A



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
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	fastio();


	int n, k;
	cin >> n >> k;
	vector <pair<int, int>> arr(n);
	map <int, int> m;
	fora(i, 0, n) {
		int a, b;
		cin >> a >> b;
		arr[i] = mp(a, b);
		if (m[a]) m[a] = min(m[a], b);
		else m[a] = b;
	} sort(all(arr));

	debug(arr)
	int ans = 0, a, b; bool flag = false;
	for (auto it = m.rbegin(); it != m.rend(); it++) {
		pair <int, int> p{it->ff, it->ss};
		auto it1 = lower_bound(all(arr), p);
		int index = it1 - arr.begin(), count = 0;

		while (true) {
			if (index == n) break;
			else if (count && arr[index - 1].ff != arr[index].ff) break;

			ans++;
			if (ans == k) {
				a = arr[index].ff; b = arr[index].ss;
				flag = true;  break;
			} else index++;
			count++;
		} if (flag) break;
	}

	debug(a) debug(b)
	ans = 0;
	fora(i, 0, n) {
		if (arr[i].ff == a && arr[i].ss == b) ans++;
	} cout << ans;

	return 0;
}