// C. Discrete Acceleration
// Link - https://codeforces.com/problemset/problem/1408/C



/*--------------------------------------👻 Yash 👻--------------------------------------*/

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
#define nline "\n"
#define mm (9*1e18)
#define mp make_pair
#define pb push_back
#define pf push_front
#define int long long
#define mn ((-9)*1e18)
#define MOD 1000000007
using namespace chrono;
#define unsigned int32_t
#define size(x) (x).size()
#define PI 3.141592653589793238462
#define all(x) (x).begin(), (x).end()
#define set_bits __builtin_popcountll
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
// typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

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
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------*/


void solve() {
	/*-------👌Never Give Up👌-------*/

	int n, l;
	cin >> n >> l;
	vector <int> arr(n + 2);
	fora(i, 1, n + 1) cin >> arr[i];

	arr.back() = l;
	vector <pair<int, double>> front(n + 2), back(n + 2);
	fora(i, 0, n + 2) {
		if (i) {
			double dist = arr[i] - arr[i - 1], speed = front[i - 1].ff, time = dist / speed;
			front[i].ff = speed + 1; front[i].ss = front[i - 1].ss + time;
		} else {
			front[i].ff = 1; front[i].ss = 0;
		}
	}
	rfora(i, 0, n + 2) {
		if (i + 1 == n + 2) {
			back[i].ff = 1; back[i].ss = 0;
		} else {
			double dist = arr[i + 1] - arr[i], speed = back[i + 1].ff, time = dist / speed;
			back[i].ff = speed + 1; back[i].ss = back[i + 1].ss + time;
		}
	}

	double time = mm;
	fora(i, 0, n + 1) {
		int j = i + 1;

		double speed1 = back[j].ff, time1 = front[i].ss - back[j].ss;
		double dist1 = arr[i], dist3 = arr[j], dist2 = speed1 * time1;
		double dist = (dist3 - dist2) - dist1, speed = front[i].ff + back[j].ff;
		time = min(time, (dist / speed) + front[i].ss);
	} cout << fixed << setprecision(10) << time << nline;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	int tt = 1;
	cin >> tt;
	while (tt--) {solve();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}