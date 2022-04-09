// D. Maximum Product Strikes Back
// Link - https://codeforces.com/contest/1660/problem/D



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

int solve(int start, int end, int &l, int &r, vector <int> &arr) {

	int total = 0, two = 0, neg = 0, cnt = 0;
	fora(i, start, end + 1) {
		if (abs(arr[i]) == 2) two++;
		if (arr[i] < 0) total++;
	}
	rfora(i, start, end + 1) {
		if (abs(arr[i]) == 2) neg++;
		cnt++;
		if (arr[i] < 0) break;
	}

	int n = (end - start) + 1, ans = 0, curr = 0, currTotal = 0, front = 0;
	if (total % 2 == 0) ans = two;

	fora(i, start, end) {
		if (abs(arr[i]) == 2) curr++;
		if (arr[i] < 0) currTotal++;
		front++;

		if (total & 1) {
			if (currTotal & 1) {
				int temp = two - curr;
				if (temp > ans) {
					ans = temp;
					l = front; r = 0;
				}
			} else {
				if (curr > ans) {
					ans = curr;
					l = 0; r = n - front;
				}
			}
		} else {
			if (currTotal & 1) {
				int temp = two - (neg + curr);
				if (temp > ans) {
					ans = temp;
					l = front; r = cnt;
				}
			}
		}
	}
	return ans;
}

void solve() {
	/*-------__👌Never Give Up👌__-------*/

	int n;
	cin >> n;
	vector <int> arr(n), zero;
	fora(i, 0, n) {
		cin >> arr[i];
		if (arr[i]) zero.pb(i);
	}

	if (zero.empty()) {
		cout << 0 << " " << n << nline;
	} else if (size(zero) == n) {
		int ans = 0, l = 0, r = n, ltemp = 0, rtemp = 0;
		if (solve(0, n - 1, ltemp, rtemp, arr) > ans) {
			l = ltemp; r = rtemp;
		} cout << l << " " << r << nline;
	} else {
		int ans = 0, l = 0, r = n, start = zero[0], ltemp = start, temp = start, end;
		fora(i, 0, size(zero)) {
			int flag = 0;
			if (temp == zero[i]) temp++;
			else {
				end = zero[i - 1];
				flag = 1;
			}

			if (i + 1 == size(zero) && !flag) {
				end = zero.back();
				flag = 1;
			}

			if (flag) {
				int ltemp = 0, rtemp = 0, store = solve(start, end, ltemp, rtemp, arr);
				if (store > ans) {
					ans = store;
					l = start + ltemp;
					r = ((n - 1) - end) + rtemp;
				}
				if (start != zero[i]) {
					start = zero[i];
					temp = start; i--;
				}
			}
		} cout << l << " " << r << nline;
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