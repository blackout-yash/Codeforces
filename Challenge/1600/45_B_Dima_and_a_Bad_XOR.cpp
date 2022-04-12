// B. Dima and a Bad XOR
// Link - https://codeforces.com/problemset/problem/1151/B



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
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------*/

void solve(int n, int m, int _xor, vector <int> &ans, vector <int> &store, vector <vector<int>> &arr) {

	int flag = 0;
	fora(i, 0, n) {
		int temp = (_xor ^ ans[i]);
		fora(j, 0, m) {
			if ((temp ^ arr[i][j])) {
				store[i] = j + 1;
				flag = 1; break;
			} if (flag) break;
		}
	}

	if (flag) {
		cout << "TAK\n";
		for (auto x : store) cout << x << " ";
		cout << nline;
	} else cout << "NIE\n";
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n, m;
	cin >> n >> m;

	vector <vector<int>> arr(n, vector<int> (m));
	int temp = mn, index = 0;
	fora(i, 0, n) {
		fora(j, 0, m) {
			cin >> arr[i][j];
			if (temp < arr[i][j]) {
				temp = arr[i][j];
				index = i;
			}
		}
	}

	vector <int> ans, store;
	fora(i, 0, n) {
		if (i == index) {
			fora(k, 0, m) {
				if (arr[i][k] == temp) {
					ans.pb(temp);
					store.pb(k + 1);
					break;
				}
			}
		} else {
			int temp1 = mm, temp2 = 0;
			fora(k, 0, m) {
				if (temp1 > arr[i][k]) {
					temp1 = arr[i][k];
					temp2 = k + 1;
				}
			} ans.pb(temp1);
			store.pb(temp2);
		}
	}

	int _xor = 0;
	for (auto x : ans) _xor ^= x;
	if (_xor) {
		cout << "TAK\n";
		for (auto x : store) cout << x << " ";
		cout << nline;
	} else solve(n, m, _xor, ans, store, arr);
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