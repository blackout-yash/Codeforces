// C. Increasing Matrix
// Link - https://codeforces.com/problemset/problem/1231/C



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


int solve(vector <vector <int>> &arr, int n, int m, int si, int sj) {
	int count = 0;
	rfora(i, 0, si + 1) {
		rfora(j, 0, sj + 1) {
			if (arr[i][j]) return arr[i][j] + count;
			count++;
		} sj = m - 1;
	} return count;
}


bool check(vector <vector <int>> &arr, int n, int m) {
	bool flag1 = true, flag2 = true;
	int prev;
	for (auto x : arr) {
		prev = mn;
		for (auto y : x) {
			if (y <= prev) {
				flag1 = false; break;
			} else prev = y;
		} if (!flag1) break;
	}

	fora(i, 0, m) {
		prev = mn;
		fora(j, 0, n) {
			if (arr[j][i] <= prev) {
				flag2 = false; break;
			} else prev = arr[j][i];
		} if (!flag2) break;
	}

	if (flag1 && flag2) return true;
	return false;
}


int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("error.txt", "w", stderr);
#endif
	fastio();


	int n, m;
	cin >> n >> m;
	vector <vector <int>> arr(n, vector <int> (m));
	fora(i, 0, n) {
		fora(j, 0, m) cin >> arr[i][j];
	}

	int temp1, temp2, temp3, temp4, temp5, temp6;
	bool flag = false;
	rfora(i, 0, n) {
		rfora(j, 0, m) {
			if (!arr[i][j]) {
				temp1 = arr[i + 1][j];
				temp2 = arr[i][j + 1];
				temp3 = solve(arr, n, m, i - 1, j);
				temp4 = solve(arr, n, m, i, j - 1);

				temp5 = min(temp1, temp2);
				temp6 = max(temp3, temp4);

				if (temp5 - 1 <= temp6) {
					flag = true; break;
				} else arr[i][j] = temp5 - 1;
			}
		} if (flag) break;
	}

	if (flag) cout << "-1";
	else {
		if (check(arr, n, m)) {
			int sum = 0;
			fora(i, 0, n) {
				fora(j, 0, m) sum += arr[i][j];
			} cout << sum;
		} else cout << "-1";
	}

	return 0;
}