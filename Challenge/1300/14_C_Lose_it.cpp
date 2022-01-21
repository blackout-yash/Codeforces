// C. Lose it!
// Link - https://codeforces.com/problemset/problem/1176/C



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

int find(vector <int> &arr, int i, int key) {
	int index = lower_bound(arr.begin() + i, arr.end(), key) - arr.begin();
	if (index >= size(arr)) return -1;
	return index;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n, ans = 0;
	cin >> n;
	vector <vector <int>> store(6);
	fora(i, 0, n) {
		int x; cin >> x;
		if (x == 4) store[0].pb(i);
		else if (x == 8) store[1].pb(i);
		else if (x == 15) store[2].pb(i);
		else if (x == 16) store[3].pb(i);
		else if (x == 23) store[4].pb(i);
		else if (x == 42) store[5].pb(i);
	}
	vector <int> arr(6, 0);
	fora(i, 0, size(store[0])) {
		int temp = store[0][i], index;

		fora(j, 1, 6) {
			index = find(store[j], arr[j], temp);
			if (index == -1) break;
			else {
				arr[j] = index + 1;
				temp = store[j][index];
			}
		} if (index == -1) break;
		else ans++;
	}

	cout << n - (ans * 6);

	return 0;
}