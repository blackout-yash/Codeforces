// B. Reverse String
// Link - https://codeforces.com/problemset/problem/1553/B



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

bool solve(string &s1, string &s2, string temp, int i) {
	while (size(s2) != size(temp)) {
		if (i < 0) break;
		temp.pb(s1[i--]);
	}

	if (s2 == temp) return true;
	return false;
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
		string s1, s2;
		cin >> s1 >> s2;

		bool flag = false;
		fora(i, 0, size(s1)) {
			if (s1[i] == s2[0]) {
				int n = size(s2), j = i, k = 0;
				string temp; temp.pb(s2[k++]);

				while (size(temp) != n) {
					if (j) {
						if (s1[j - 1] == s2[k]) flag = solve(s1, s2, temp, j - 1);
					} if (flag) break;

					if (j + 1 != size(s1) && s1[j + 1] == s2[k]) temp.pb(s1[++j]);
					else break;
					k++;
				}
				if (temp == s2 || flag) {
					flag = true; break;
				}
			}
		}
		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}