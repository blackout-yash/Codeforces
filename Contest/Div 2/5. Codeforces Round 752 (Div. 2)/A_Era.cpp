// A. Era
// Link - https://codeforces.com/contest/1604/problem/A



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, x, ans = 0;
		cin >> n;

		fora(i, 1, n + 1) {
			cin >> x;
			int diff = x - i;
			if (diff > 0) {
				if (ans < diff) ans += (diff - ans);
			}
		} cout << ans << "\n";
	}

	return 0;
}