// B. A New Technique
// Link - https://codeforces.com/problemset/problem/1413/B



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
#define mm INT_MAX
#define mn INT_MIN
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

bool isSame(vector <int> &arr, vector <int> &temp) {
	fora(i, 0, size(arr)) {
		if (arr[i] != temp[i]) return false;
	} return true;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	fastio();


	int tt;
	cin >> tt;
	while (tt--) {
		int n, m;
		cin >> n >> m;
		vector <vector<int>> row(n, vector <int> (m)), column(m, vector <int> (n));
		vector <int> store(n), temp; map <int, int> map;
		fora(i, 0, n) {
			fora(j, 0, m) {
				cin >> row[i][j];
				if (!j) {
					store[i] = row[i][j];
					map[row[i][j]] = i;
				}
			}
		} sort(all(store));
		fora(i, 0, m) {
			fora(j, 0, n) cin >> column[i][j];
		}

		for (auto x : column) {
			temp = x;
			sort(all(temp));
			if (isSame(store, temp)) {
				store = x; break;
			}
		}

		for (auto x : store) {
			int index = map[x];
			fora(i, 0, m) cout << row[index][i] << " ";
			cout << nline;
		}
	}

	return 0;
}