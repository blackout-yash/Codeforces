// B. Find the Spruce
// Link - https://codeforces.com/problemset/problem/1461/B



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


	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, ans = 0;
		cin >> n >> m;
		vector <vector <char>> ch(n, vector <char> (m));
		vector < vector <int>> store(n, vector <int> (m));
		fora(i, 0, n) {
			int count = 0;
			fora(j, 0, m) {
				cin >> ch[i][j];
				if (ch[i][j] == '*') count++;
				store[i][j] = count;
			}
		}

		fora(i, 0, n) {
			fora(j, 0, m) {
				int size = 0, temp = 0;
				if (ch[i][j] == '*') {
					int index1 = j, index2 = j;
					fora(k, i, n) {
						if (index1 < 0) break;
						if (index2 >= m) break;

						int temp1 = store[k][index1], temp2 = store[k][index2];
						if (ch[k][index1] == '*' && ch[k][index2] == '*' && temp2 - temp1 == temp) {
							size++; temp += 2;
							index1--; index2++;
						} else break;
					} ans += size;
				}
			}
		} cout << ans << nline;
	}

	return 0;
}