// C1. Skyscrapers (easy version)
// Link - https://codeforces.com/contest/1313/problem/C1



/*--------------------------------------👻 Yash 👻--------------------------------------*/
/*----------------------------------😔 Editorial Op! 😔---------------------------------*/

// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// #pragma GCC optimize("Ofast")
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

	int n;
	cin >> n;
	vector <int> arr(n + 2), leftArea(n + 1), rightArea(n + 2);
	fora(i, 1, n + 1) cin >> arr[i];

	fora(i, 1, n + 1) {
		int size = 0, j = i;
		while (true) {
			if (arr[i] <= arr[j]) size++;
			else break;

			if (!j) break;
			else j--;
		} leftArea[i] = leftArea[j] + (arr[i] * size);
	}

	rfora(i, 1, n + 2) {
		int size = 0, j = i;
		while (true) {
			if (arr[i] <= arr[j]) size++;
			else break;

			if (j == n + 1) break;
			else j++;
		} rightArea[i] = rightArea[j] + (arr[i] * size);
	}

	int max = 0, index;
	fora(i, 1, n + 1) {
		int area = leftArea[i] + rightArea[i] - arr[i];
		if (max < area) {
			max = area;
			index = i;
		}
	}

	rfora(i, 1, index) {
		if (arr[i] >= arr[i + 1]) arr[i] = arr[i + 1];
	}
	fora(i, index + 1, n + 1) {
		if (arr[i] >= arr[i - 1]) arr[i] = arr[i - 1];
	}

	for (auto x : arr) (x) ? cout << x << " " : cout << "";
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	auto start1 = high_resolution_clock::now();
	int tt = 1;
	// cin >> tt;
	while (tt--) {solve();}
	auto stop1 = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop1 - start1);
#ifndef ONLINE_JUDGE
	cerr << "Time: " << duration . count() / 1000 << "ms" << endl;
#endif
	return 0;
}