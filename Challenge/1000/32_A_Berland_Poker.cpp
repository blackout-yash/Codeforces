// A. Berland Poker
// Link - https://codeforces.com/problemset/problem/1359/A



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n"
#define size(x) (x).size()
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, k;
		cin >> n >> m >> k;
		vector <int> arr(k, 0);
		int max = n / k;
		fora(i, 0, k) {
			if (!m) break;
			if (i) {
				arr[i]++;
				m--;
			} else {
				if (m >= max) {
					arr[i] = max;
					m -= max;
				} else {
					arr[i] = m;
					m = 0;
				}
			}
			if (i + 1 == k) i = 0;
		} cout << arr[0] - arr[1] nline;
	}

	return 0;
}