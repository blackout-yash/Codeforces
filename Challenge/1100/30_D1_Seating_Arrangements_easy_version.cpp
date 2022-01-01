// D1. Seating Arrangements (easy version)
// Link - https://codeforces.com/problemset/problem/1566/D1



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

int solve(vector <int> &ans, int index) {
	int count = 0;
	fora(i, 0, index) {
		if (ans[i]) count++;
	} ans[index] = 1;
	return count;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	fastio();

	int tt;
	cin >> tt;
	while (tt--) {
		int n, size, count = 0;
		cin >> n >> size;
		vector <int> arr(size), temp(size), ans(size, 0);
		map <int, int> m;
		fora(i, 0, size) {
			cin >> arr[i];
			m[arr[i]]++; temp[i] = arr[i];
		} sort(all(temp));

		fora(i, 0, size) {
			if (m[arr[i]] == 1) {
				int index = lower_bound(all(temp), arr[i]) - temp.begin();
				count += solve(ans, index);
			} else {
				int index = lower_bound(all(temp), arr[i]) - temp.begin();
				count += solve(ans, index + (m[arr[i]] - 1)); m[arr[i]]--;
			}
		} cout << count << nline;

	}
	return 0;
}