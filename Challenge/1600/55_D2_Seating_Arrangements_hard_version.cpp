// D2. Seating Arrangements (hard version)
// Link - https://codeforces.com/problemset/problem/1566/D2



/*--------------------------------------👻 Yash 👻--------------------------------------*/

#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#endif

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds; // find_by_order, order_of_key

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
void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
/*----------------------------------------------------------------------------------------*/
pair<int, int> solve(int index, int m, pbds &s) {
	int temp1 = s.order_of_key(index), temp2 = size(s) - temp1, temp3 = m - (index + temp2 + 1);
	return {temp1, temp1 + temp3};
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n, m, ans = 0;
	cin >> n >> m;

	vector <pair<int, int>> arr(n * m);
	fora(i, 0, n * m) {
		cin >> arr[i].ff;
		arr[i].ss = i;
	} sort(all(arr));

	int k = (n * m) - 1;
	fora(i, 0, n) {
		vector <pair<int, int>> temp;
		fora(j, 0, m) {
			temp.pb({arr[k].ss, arr[k].ff});
			k--;
		} sort(all(temp));

		map <int, pair<int, int>> range;
		int index = 0;
		fora(j, k + 1, k + 1 + m) {
			if (range.count(arr[j].ff)) range[arr[j].ff].ff = index;
			else range[arr[j].ff].ff = range[arr[j].ff].ss = index;
			index++;
		}

		vector <int> store;
		pbds s;
		for (auto x : temp) {
			int num = x.ss, low = range[num].ss, high = range[num].ff;

			pair<int, int> temp1 = solve(low, m, s), temp2 = solve(high, m, s);

			if (temp1.ss > temp2.ss) {
				s.insert(high);
				range[num].ff--;
				ans += temp2.ff;
			} else {
				s.insert(low);
				range[num].ss++;
				ans += temp1.ff;
			}
		}
	} cout << ans << nline;
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