// A. Boboniu Likes to Color Balls
// Link - https://codeforces.com/problemset/problem/1395/A



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
		vector <int> odd, even;
		int x, n1 = 0, n2 = 1;
		fora(i, 0, 4) {
			cin >> x;
			if (i == 3) {
				if (x & 1) n2 = 0;
			}
			else if (x & 1) odd.pb(x);
			else even.pb(x);
		}
		sort(even.begin(), even.end());
		sort(odd.begin(), odd.end());

		n1 = size(even);
		if (n1 + n2 >= 3) cout << "YES\n";
		else if (n1 == 2) {
			if (n2) cout << "YES\n";
			else cout << "NO\n";
		} else if (n1 == 1) {
			if (n2) cout << "NO\n";
			else if (even[0] != 0) cout << "YES\n";
			else cout << "NO\n";
		} else cout << "YES\n";
	}

	return 0;
}