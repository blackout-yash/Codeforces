// C. Complex Market Analysis
// Link - https://codeforces.com/problemset/problem/1609/C



/*--------------------------------------👻 Yash 👻 --------------------------------------*/
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

const int range = 1e6;
bitset < range + 5 > b;
vector <int> prime;

void sieve() {
	b.set();

	b[0] = b[1] = 0;

	for (int i = 2; i <= range; i++) {
		if (b[i]) {
			prime.push_back(i);
			for (int j = i * i; j <= range; j += i) {
				b[j] = 0;
			}
		}
	}
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif
	fastio();
	/*-------👌Never Give Up👌-------*/

	sieve();
	int tt;
	cin >> tt;
	while (tt--) {
		int n, k;
		cin >> n >> k;
		vector <int> arr(n), one(n);
		fora(i, 0, n) {
			cin >> arr[i];
			if (arr[i] == 1) one[i] = 1;
		}

		map <int, int> front, back;
		fora(i, 1, n + 1) {
			if (!front[i]) {
				int temp = 0;
				for (int j = i; j < n + 1; j += k) {
					if (one[j - 1]) temp++;
					else temp = 0;
					if (temp) front[j] = temp;
					else front[j] = -1;
				}
			}
		}
		rfora(i, 1, n + 1) {
			if (!back[i]) {
				int temp = 0;
				for (int j = i; j >= 1; j -= k) {
					if (one[j - 1]) temp++;
					else temp = 0;
					if (temp) back[j] = temp;
					else back[j] = -1;
				}
			}
		}

		int ans = 0;
		fora(i, 0, n) {
			if (binary_search(all(prime), arr[i])) {
				int temp1 = front[(i + 1) - k], temp2 = back[i + 1 + k];
				if (!temp1) temp1 = -1;
				if (!temp2) temp2 = -1;

				if (temp1 == -1 && temp2 == -1) {}
				else if (temp1 != -1 && temp2 != -1) {
					ans += (temp1 * (temp2 + 1));
					ans += temp2;
				} else if (temp1 == -1) ans += temp2;
				else ans += temp1;
			}
		} cout << ans << nline;
	}


	return 0;
}