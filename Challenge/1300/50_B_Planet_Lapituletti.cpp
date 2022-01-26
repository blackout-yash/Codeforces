// B. Planet Lapituletti
// Link - https://codeforces.com/problemset/problem/1493/B



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

bool fun(int n) {
	if (n == 0 || n == 1 || n == 2 || n == 5 || n == 8) return true;
	return false;
}

void replace(string &temp) {
	fora(i, 0, size(temp)) {
		if (temp[i] == '2') temp[i] = '5';
		else if (temp[i] == '5') temp[i] = '2';
	}
}

bool solve(int n, int key) {
	string temp = to_string(n);
	replace(temp);
	fora(i, 0, size(temp)) {
		int num = unsigned(temp[i] - '0');
		if (!fun(num)) return false;
	} reverse(all(temp));
	if (size(temp) == 1) temp.pb('0');

	if (stoi(temp) + 1 > key) return false;
	return true;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	int tt;
	cin >> tt;
	while (tt--) {
		int hr, min, hr1, min1; char ch;
		cin >> hr >> min >> hr1 >> ch >> min1;

		int hour = hr1, minute = min1, flag = 0;
		while (true) {
			while (true) {
				if (solve(hour, min) && solve(minute, hr)) {
					flag = 1; break;
				} else minute++;

				if (minute == min) break;
			} if (flag) break;
			else {hour++; minute = min1 = 0;}
			if (hour == hr) hour = 0;
		}

		if (hour < 10) cout << "0";
		cout << hour << ":";
		if (minute < 10) cout << "0";
		cout << minute << nline;
	}

	return 0;
}