// C. Diamond Miner
// Link - https://codeforces.com/contest/1496/problem/C



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int32_t main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> x, y;
		fora(i, 0, 2 * n) {
			int a, b;
			cin >> a >> b;
			if (a) x.push_back(abs(a));
			else y.push_back(abs(b));
		}

		sort(x.begin(), x.end()); sort(y.begin(), y.end());

		double ans = 0;
		fora(i, 0, n) {
			ans += (sqrt(1.0 * x[i] * x[i] + 1.0 * y[i] * y[i]));
		}

		printf("%0.15lf\n", ans);
	}

	return 0;
}