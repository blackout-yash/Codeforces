// A. Sorting by Subsequences
// Link - https://codeforces.com/problemset/problem/843/A



/*--------------------------------------👻 Yash 👻--------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
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


	int n;
	cin >> n;
	vector <int> arr(n);
	fora(i, 0, n) cin >> arr[i];
	vector <int> sorted = arr;
	sort(all(sorted));

	vector <vector<int>> ans;
	fora(i, 0, n) {
		if (arr[i] != -1) {
			vector <int> temp;
			temp.pb(1); temp.pb(i + 1);
			if (arr[i] == sorted[i]) ans.pb(temp);
			else {
				int store = arr[i];
				while (true) {
					int index = lower_bound(all(sorted), store) - sorted.begin();
					store = arr[index]; temp.pb(index + 1); arr[index] = -1;
					if (store == sorted[i]) {
						temp[0] = size(temp) - 1;
						ans.pb(temp); break;
					}
				}
			} arr[i] = -1;
		}
	} cout << size(ans) << nline;
	for (auto x : ans) {
		for (auto y : x) cout << y << " ";
		cout << nline;
	}

	return 0;
}