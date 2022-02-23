// D. a-Good String
// Link - https://codeforces.com/problemset/problem/1385/D



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

int solve(string &s, char ch, int i, int req, int size, int fact) {
	int ans = 0;
	if (fact == -1) {
		if (s[i] == ch) {}
		else ans++;

		if (req == size + 1) {
			if (size == 0) {
				if (s[i - 1] != ch + 1) ans++;
			} else {
				ans += min(solve(s, ch + 1, i - 1, req / 2, 0, -1), solve(s, ch + 1, i - req, req / 2, 0, 1));
			}
		} else ans += solve(s, ch, i - 1, req, size + 1, fact);
	} else {
		if (s[i] == ch) {}
		else ans++;

		if (req == size + 1) {
			if (size == 0) {
				if (s[i + 1] != ch + 1) ans++;
			} else {
				ans += min(solve(s, ch + 1, i + 1, req / 2, 0, 1), solve(s, ch + 1, i + req, req / 2, 0, -1));
			}
		} else ans += solve(s, ch, i + 1, req, size + 1, fact);
	} return ans;
}

int count(string &s, int start, int end) {
	int ans = end - start;
	fora(i, start, end) {
		if (s[i] == 'a') ans--;
	} return ans;
}

void solve() {
	/*-------👌Never Give Up👌-------*/

	int n; string s;
	cin >> n >> s;

	if (n == 1) {
		if (s == "a") cout << "0\n";
		else cout << "1\n";
	} else if (n == 2) {
		int cnt = 0;
		if (s[0] == 'a' || s[1] == 'a') cnt++;
		if (s[0] == 'b' || s[1] == 'b') cnt++;
		cout << 2 - cnt << nline;
	} else {
		int temp1 = count(s, 0, n / 2), temp2 = count(s, n / 2, n);
		int temp3 = min(solve(s, 'b', 0, n / 4, 0, 1), solve(s, 'b', (n / 2) - 1, n / 4, 0, -1)),
		    temp4 = min(solve(s, 'b', n / 2, n / 4, 0, 1), solve(s, 'b', n - 1, n / 4, 0, -1));
		cout << min(temp1 + temp4, temp2 + temp3) << nline;
	}
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