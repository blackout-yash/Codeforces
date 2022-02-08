// E. Anfisa the Monkey
// Link - https://codeforces.com/problemset/problem/44/E



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


	int k, a, b; string s;
	cin >> k >> a >> b >> s;

	int n = size(s), sum = n, flag = 1;
	vector <int> arr(k);
	fora(i, 0, k) {
		if (i + 1 == k) {
			if (sum >= a) arr[i] = sum;
			else flag = 0;
		} else arr[i] = a;
		sum -= a;
	}

	if (flag) {
		sum = 0;
		rfora(i, 0, k) {
			if (arr[i] >= b) {
				sum += (arr[i] - b);
				arr[i] = b;
			} else {
				if (sum >= (b - arr[i])) {
					sum -= (b - arr[i]);
					arr[i] = b;
				} else {
					arr[i] += sum;
					sum = 0;
				}
			}
		}

		if (sum) cout << "No solution";
		else {
			int index = 0;
			for (auto x : arr) {
				cout << s.substr(index, x) << nline;
				index += x;
			}
		}
	} else cout << "No solution";

	return 0;
}