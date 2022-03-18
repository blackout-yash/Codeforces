// D1. Prefix-Suffix Palindrome (Easy version)
// Link - https://codeforces.com/problemset/problem/1326/D1



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

void solve(int l, int r, string &s, string &ans1, string &ans2, int flag) {

	string temp1, temp2, temp3, temp4;
	int size = (r - l) + 1, cnt = 0, req = size / 2;
	if (size & 1) req++;
	while (l <= r) {
		if (s[l] == s[r]) {
			temp1.pb(s[l]);
			if (l != r) temp2.pb(s[r]);
		} else break;
		l++; r--; cnt++;
	}

	if (flag) {
		rfora(i, l, r + 1) {
			int start = l, end = i, size = (i - l) + 1, cnt = 0, req = size / 2;
			if (size & 1) req++;
			while (start <= end) {
				if (s[start] == s[end]) {}
				else break;
				cnt++; start++; end--;
			}
			if (req == cnt) {
				temp3 = s.substr(l, size);
				break;
			}
		}

		fora(i, l, r + 1) {
			int start = i, end = r, size = (r - i) + 1, cnt = 0, req = size / 2;
			if (size & 1) req++;
			while (start <= end) {
				if (s[start] == s[end]) {}
				else break;
				cnt++; start++; end--;
			}
			if (req == cnt) {
				temp4 = s.substr(i, size);
				break;
			}
		}
	}


	int n1 = size(temp1), n2 = size(temp2), n3 = size(temp3), n4 = size(temp4), n5 = size(ans1), n6 = size(ans2);
	if (flag) {
		if (n1 + n2 + n3 > n5 + n6) {
			ans1 = temp1 + temp3;
			ans2 = temp2;
		}

		n5 = size(ans1); n6 = size(ans2);
		if (n1 + n2 + n4 > n5 + n6) {
			ans1 = temp1;
			ans2 = temp2 + temp4;
		}
	} else if (n1 + n2 > n5 + n6 && req == cnt) {
		ans1 = temp1;
		ans2 = temp2;
	}
}


void solve() {
	/*-------👌Never Give Up👌-------*/

	string s, ans1, ans2;
	cin >> s;

	int n = size(s);
	fora(i, 0, n) solve(0, i, s, ans1, ans2, 0);
	rfora(i, 0, n) solve(i, n - 1, s, ans1, ans2, 0);
	solve(0, n - 1, s, ans1, ans2, 1);

	reverse(all(ans2));
	cout << ans1 << ans2 << nline;
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