// D. Bishwock
// Link - https://codeforces.com/problemset/problem/991/D



/*--------------------------------------👻 Yash 👻--------------------------------------*/

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
string s[2];

bool up1(int x, int y) {
	if (y + 1 >= size(s[0])) return false;
	else if (s[x][y] == '0' && s[x - 1][y] == '0' && s[x - 1][y + 1] == '0') {
		s[x][y] = s[x - 1][y] = s[x - 1][y + 1] = '*';
		return true;
	} return false;
}

bool up2(int x, int y) {
	if (y - 1 <= -1) return false;
	else if (s[x][y] == '0' && s[x - 1][y] == '0' && s[x - 1][y - 1] == '0') {
		s[x][y] = s[x - 1][y] = s[x - 1][y - 1] = '*';
		return true;
	} return false;
}

bool up3(int x, int y) {
	if (y - 1 <= -1) return false;
	else if (s[x][y] == '0' && s[x + 1][y] == '0' && s[x + 1][y - 1] == '0') {
		s[x][y] = s[x + 1][y] = s[x + 1][y - 1] = '*';
		return true;
	} return false;
}

bool up4(int x, int y) {
	if (y + 1 >= size(s[0])) return false;
	else if (s[x][y] == '0' && s[x + 1][y] == '0' && s[x + 1][y + 1] == '0') {
		s[x][y] = s[x + 1][y] = s[x + 1][y + 1] = '*';
		return true;
	} return false;
}

bool down1(int x, int y) {
	if (y + 1 >= size(s[0])) return false;
	else if (s[x][y] == '0' && s[x][y + 1] == '0' && s[x - 1][y + 1] == '0') {
		s[x][y] = s[x][y + 1] = s[x - 1][y + 1] = '*';
		return true;
	} return false;
}

bool down2(int x, int y) {
	if (y - 1 <= -1) return false;
	else if (s[x][y] == '0' && s[x][y - 1] == '0' && s[x - 1][y - 1] == '0') {
		s[x][y] = s[x][y - 1] = s[x - 1][y - 1] = '*';
		return true;
	} return false;
}

bool down3(int x, int y) {
	if (y - 1 <= -1) return false;
	else if (s[x][y] == '0' && s[x][y - 1] == '0' && s[x + 1][y - 1] == '0') {
		s[x][y] = s[x][y - 1] = s[x + 1][y - 1] = '*';
		return true;
	} return false;
}

bool down4(int x, int y) {
	if (y + 1 >= size(s[0])) return false;
	else if (s[x][y] == '0' && s[x][y + 1] == '0' && s[x + 1][y + 1] == '0') {
		s[x][y] = s[x][y + 1] = s[x + 1][y + 1] = '*';
		return true;
	} return false;
}

void solve() {
	/*-------👌Never Give Up👌-------*/

	cin >> s[0] >> s[1];

	int ans = 0;
	fora(i, 0, 2) {
		fora(j, 0, size(s[0])) {
			if (i) {
				if (down2(i, j)) ans++;
				if (up2(i, j)) ans++;
				if (up1(i, j)) ans++;
				if (down1(i, j)) ans++;
			} else {
				if (down3(i, j)) ans++;
				if (up3(i, j)) ans++;
				if (up4(i, j)) ans++;
				if (down4(i, j)) ans++;
			}
		}
	} cout << ans;
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