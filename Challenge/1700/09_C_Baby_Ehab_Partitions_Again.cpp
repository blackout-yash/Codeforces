// C. Baby Ehab Partitions Again
// Link - https://codeforces.com/contest/1516/problem/C



/*--------------------------------------👻 Yash 👻--------------------------------------*/
/*----------------------------------😔 Editorial Op! 😔---------------------------------*/

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
#define double long double
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
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]\n";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------*/

bool solve(int j, vector <int> &arr) {
	int sum = 0, n = size(arr);
	fora(i, 0, n) {
		if (i != j) sum += arr[i];
	}

	set <int> s;
	s.insert(0);
	fora(i, 0, n) {
		if (i != j) {
			vector <int> temp;
			for (auto y : s) {
				int sum1 = y + arr[i], sum2 = sum - sum1;
				temp.pb(sum1);
				if (sum1 == sum2) return false;
			}
			for (auto x : temp) s.insert(x);
		}
	}
	return true;
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n;
	cin >> n;
	vector <int> arr(n);

	int index = 0;
	fora(i, 0, n) {
		cin >> arr[i];
		if (arr[i] & 1) index = i + 1;
	}

	if (solve(-1, arr)) cout << "0";
	else {
		cout << 1 << " ";
		if (index) cout << index;
		else {
			int min = mm, index;
			fora(i, 0, n) {
				int cnt = 0;
				while (true) {
					if (arr[i] && !(arr[i] & 1)) {}
					else break;
					cnt++; arr[i] /= 2;
				}
				if (cnt < min) {
					min = cnt;
					index = i + 1;
				}
			} cout << index;
		}
	}
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