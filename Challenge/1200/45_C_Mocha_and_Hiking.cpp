// C. Mocha and Hiking
// Link - https://codeforces.com/problemset/problem/1559/C



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


	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector <pair<int, int>> arr(n);
		fora(i, 0, n) {
			int x; cin >> x;
			if (x) arr[i] = mp(n + 1, i + 1);
			else arr[i] = mp(i + 1, n + 1);
		} sort(all(arr));

		pair <int, int> p1 = mp(1, n + 1), p2 = mp(n + 1, 2);
		bool flag = false, flag1 , flag2;


		p1 = mp(n, n + 1);
		flag1 = binary_search(all(arr), p1);
		if (flag1) {
			flag = true;
			for (int i = 1; i < n + 2; i++) cout << i << " ";
			cout << nline;
		}

		if (!flag) {
			p1 = mp(n + 1, 1);
			flag1 = binary_search(all(arr), p1);
			if (flag1) {
				flag = true;
				cout << n + 1 << " ";
				for (int i = 1; i < n + 1; i++) cout << i << " ";
				cout << nline;
			}
		}

		if (!flag) {
			fora(i, 1, n) {
				p1 = mp(i, n + 1);
				p2 = mp(n + 1, i + 1);
				flag1 = binary_search(all(arr), p1);
				flag2 = binary_search(all(arr), p2);

				if (flag1 && flag2) {
					flag = true;
					for (int j = 1; j < n + 1; j++) {
						if (j == i) cout << i << " " << n + 1 << " ";
						else cout << j << " ";
					}
					cout << nline;
					break;
				}
			}
		}

		if (!flag) cout << "-1\n";
	}

	return 0;
}