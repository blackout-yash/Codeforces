// B. New Theatre Square
// Link - https://codeforces.com/problemset/problem/1359/B



#include <bits/stdc++.h>
using namespace std;
#define ll int
#define fora(i,a,b) for(ll i=a;i<b;i++)

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m, x, y;
		cin >> n >> m >> x >> y;
		char arr[n][m];
		fora(i, 0, n) {
			fora(j, 0, m) {
				cin >> arr[i][j];
			}
		}

		int ans = 0;
		fora(i, 0, n) {
			fora(j, 0, m) {
				if (arr[i][j] == '.') {
					if (j + 1 == m) ans += x;
					else {
						if (arr[i][j + 1] == '.') {
							ans += min(2 * x, y);
							j++;
						}
						else ans += x;
					}
				}
			}
		} cout << ans << "\n";
	}
	return 0;
}