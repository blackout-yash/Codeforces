// N. Waste Sorting
// Link - https://codeforces.com/problemset/problem/1468/N



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b) for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n"
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int c[3], a[5];
		fora(i, 0, 3) cin >> c[i];
		fora(i, 0, 5) cin >> a[i];

		c[0] -= a[0]; c[1] -= a[1]; c[2] -= a[2];
		if (c[0] >= 0 && a[3]) {
			if (c[0] >= a[3]) c[0] = 0;
			else {
				c[2] -= (a[3] - c[0]);
				c[0] = 0;
			}
		}

		if (c[1] >= 0 && a[4]) {
			if (c[1] >= a[4]) c[1] = 0;
			else {
				c[2] -= (a[4] - c[1]);
				c[1] = 0;
			}
		}

		bool flag = true;
		fora(i, 0, 3) {
			if (c[i] < 0) {
				flag = false;
				break;
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}