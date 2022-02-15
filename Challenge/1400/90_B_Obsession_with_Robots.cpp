// B. Obsession with Robots
// Link - https://codeforces.com/problemset/problem/8/B



/*--------------------------------------👻 Yash 👻--------------------------------------*/
#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);
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
map<pair<int, int>, int> m;
bool isValid(char ch, int x, int y) {
	bool flag1, flag2, flag3, flag4;
	if (ch == 'R') flag1 = 0;
	else flag1 = m[ {x - 1, y}];

	if (ch == 'U') flag2 = 0;
	else flag2 = m[ {x, y - 1}];

	if (ch == 'L') flag3 = 0;
	else flag3 = m[ {x + 1, y}];

	if (ch == 'D') flag4 = 0;
	else flag4 = m[ {x, y + 1}];

	if (flag1 || flag2 || flag3 || flag4) return 1;
	return 0;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/


	string s;
	cin >> s;

	int x = 0, y = 0, flag = 1;
	m[ {x, y}] = 1;
	fora(i, 0, size(s)) {
		if (s[i] == 'R') x++;
		else if (s[i] == 'L') x--;
		else if (s[i] == 'U') y++;
		else y--;


		if (m[ {x, y}]) flag = 0;
		else if (isValid(s[i], x, y)) flag = 0;
		else m[ {x, y}] = 1;
	}(flag) ? cout << "OK" : cout << "BUG";

	return 0;
}