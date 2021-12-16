// C. Slay the Dragon
// Link - https://codeforces.com/problemset/problem/1574/C



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int solve(int x, int y, int max, int sum) {
	int ans = 0; sum -= max;
	if (x > max) ans += (x - max);
	if (y > sum) ans += (y - sum);
	return ans;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m, maximum = INT_MIN, temp = 0;
	cin >> n;
	int power[n];
	fora(i, 0, n) {
		cin >> power[i];
		temp += power[i];
		maximum = max(maximum, power[i]);
	} sort(power, power + n);

	int t;
	cin >> t;
	while (t--) {
		int x, y, max = maximum, sum = temp;
		cin >> x >> y;

		auto it = lower_bound(power, power + n, x);
		int index = it - power;
		if (index != n) {
			max = power[index];
			if (max != x) {
				if (index) cout << min(solve(x, y, power[index], sum), solve(x, y, power[index - 1], sum)) << "\n";
				else cout << solve(x, y, max, sum) << "\n";
			} else cout << solve(x, y, max, sum) << "\n";
		} else cout << solve(x, y, max, sum) << "\n";
	}

	return 0;
}