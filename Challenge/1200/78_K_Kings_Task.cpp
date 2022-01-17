// K. King's Task
// Link - https://codeforces.com/problemset/problem/1510/K



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


void full(vector <int> &arr) {
	int l = 0, r = size(arr) / 2;
	while (r != size(arr)) swap(arr[l++], arr[r++]);
}

void half(vector <int> &arr) {
	for (int i = 0; i < size(arr); i += 2) {
		swap(arr[i], arr[i + 1]);
	}
}

int solve(vector <int> &ans, vector <int> arr, bool flag) {
	int count = 0, temp = 0;
	while (true) {
		if (arr == ans) {
			temp = 1;
			break;
		} else if (count > size(arr)) break;

		if (flag) {
			half(arr);
			flag = false;
		} else {
			full(arr);
			flag = true;
		} count++;
	}
	if (temp) return count;
	else return -1;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n;
	cin >> n;
	vector <int> arr(2 * n), ans(2 * n);
	fora(i, 0, 2 * n) {
		cin >> arr[i];
		ans[i] = i + 1;
	}

	int ans1 = solve(ans, arr, true), ans2 = solve(ans, arr, false);

	if (ans1 == -1 && ans2 == -1) cout << -1;
	else if (ans1 != -1 && ans2 != -1) cout << min(ans1, ans2);
	else if (ans1 == -1)cout << ans2;
	else cout << ans1;


	return 0;
}