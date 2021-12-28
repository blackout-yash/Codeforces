// B1. TV Subscriptions (Easy Version)
// Link - https://codeforces.com/problemset/problem/1225/B1



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
		int n, k, d;
		cin >> n >> k >> d;
		vector <int> arr(n);
		fora(i, 0, n) cin >> arr[i];

		map <int, int> m;
		int count, minimum = INT_MAX;
		fora(i, 0, n) {
			m.clear(); count = 0;
			fora(j, i, n) {
				count++;
				m[arr[j]]++;
				if (count == d) break;
			} if (count == d)minimum = min(long(minimum), long(size(m)));
		} cout << minimum nline;
	}

	return 0;
}