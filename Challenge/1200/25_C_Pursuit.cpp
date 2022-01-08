// C. Pursuit
// Link - https://codeforces.com/problemset/problem/1530/C



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


	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector <int> a(n), b(n), sum1(n), sum2(n);
		fora(i, 0, n) cin >> a[i];
		fora(i, 0, n) cin >> b[i];
		sort(all(a)); sort(all(b));

		fora(i, 0, n) {
			if (i) sum1[i] = a[i] + sum1[i - 1];
			else sum1[i] = a[i];
		}
		fora(i, 0, n) {
			if (i) sum2[i] = b[i] + sum2[i - 1];
			else sum2[i] = b[i];
		}

		int temp, temp1 = sum1[n - 1], temp2 = sum2[n - 1], temp3, temp4;
		fora(i, 0, n + 1) {
			temp = (n + i) / 4; temp--;

			if (temp > -1) temp3 = temp1 - sum1[temp];
			else temp3 = temp1;

			temp -= i;
			if (temp > -1)  temp4 = temp2 - sum2[temp];
			else temp4 = temp2;

			if (temp3 >= temp4) {
				cout << i << nline;
				break;
			} else temp1 += 100;
		}
	}

	return 0;
}