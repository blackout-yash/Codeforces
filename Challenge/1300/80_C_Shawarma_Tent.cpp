// C. Shawarma Tent
// Link - https://codeforces.com/problemset/problem/1271/C



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

int solve(vector <pair<int, int>> &arr, int n, int sx, int sy, int temp1, int temp2) {
	int count = 0;
	fora(j, 0, n) {
		int dist1 = abs(sx - arr[j].ff) + abs(sy - arr[j].ss);
		int dist2 = abs(sx - temp1) + abs(sy - temp2);
		int dist3 = abs(temp1 - arr[j].ff) + abs(temp2 - arr[j].ss);

		if (dist1 == dist2 + dist3) count++;
	} return count;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int n, sx, sy;
	cin >> n >> sx >> sy;
	vector <pair<int, int>> arr(n);
	fora(i, 0, n) cin >> arr[i].ff >> arr[i].ss;

	int temp1 = -1, temp2, max = 0;
	pair <int, int> store;
	fora(i, 0, 3) {
		temp2 = -1;
		fora(j, 0, 3) {
			int temp = solve(arr, n, sx, sy, sx + temp1, sy + temp2);
			if (temp1 == 0 && temp2 == 0) temp = 0;

			if (max < temp) {
				max = temp;
				store = mp(sx + temp1, sy + temp2);
			} temp2++;
		} temp1++;
	} cout << max << nline << store.ff << " " << store.ss;

	return 0;
}