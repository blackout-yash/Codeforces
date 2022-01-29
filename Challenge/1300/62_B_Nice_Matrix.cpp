// B. Nice Matrix
// Link - https://codeforces.com/problemset/problem/1422/B



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


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		int arr[n][m];
		fora(i, 0, n) {
			fora(j, 0, m) cin >> arr[i][j];
		}

		int ans = 0;
		fora(i, 0, ceil((double)n / 2)) {
			fora(j, 0, ceil((double)m / 2)) {
				int row = (n - i) - 1, col = (m - j) - 1;
				int temp1 = arr[i][j], temp2 = arr[i][col], temp3 = arr[row][j], temp4 = arr[row][col];

				int min1 = abs(temp1 - temp2) + abs(temp1 - temp3) + abs(temp1 - temp4);
				int min2 = abs(temp2 - temp1) + abs(temp2 - temp3) + abs(temp2 - temp4);
				int min3 = abs(temp3 - temp1) + abs(temp3 - temp2) + abs(temp3 - temp4);
				int min4 = abs(temp4 - temp1) + abs(temp4 - temp2) + abs(temp4 - temp3);

				if (i == row || j == col) ans += (min(min1, min(min2, min(min3, min4))) / 2);
				else ans += min(min1, min(min2, min(min3, min4)));
			}
		} cout << ans << nline;
	}
	return 0;
}