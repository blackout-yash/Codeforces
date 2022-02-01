// B. New Year and Ascent Sequence
// Link - https://codeforces.com/problemset/problem/1284/B



/*--------------------------------------👻 Yash 👻--------------------------------------*/
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

	int n, x, y, flag, prev;
	cin >> n;
	vector <int> temp1, temp2;
	fora(i, 0, n) {
		cin >> x;
		flag = 1; prev = mm;
		int minimum = mm, maximum = mn;
		fora(j, 0, x) {
			cin >> y;
			minimum = min(minimum, y);
			maximum = max(maximum, y);
			if (prev != mm) {
				if (prev < y) flag = 0;
			} prev = min(prev, y);
		}
		if (flag) {
			temp1.pb(minimum);
			temp2.pb(maximum);
		}
	} sort(all(temp1)); sort(all(temp2));

	int size = n - size(temp1), ans = size * (n + size(temp1)), temp = 0;

	fora(i, 0, size(temp1)) {
		int index = upper_bound(all(temp2), temp1[i]) - temp2.begin();
		temp += (size(temp2) - index);
	}

	fora(i, 0, size(temp2)) {
		int index = lower_bound(all(temp1), temp2[i]) - temp1.begin();
		if (index == size(temp1) || temp1[index] >= temp2[i]) index--;
		temp += (index + 1);
	} cout << ans + (temp / 2);


	return 0;
}