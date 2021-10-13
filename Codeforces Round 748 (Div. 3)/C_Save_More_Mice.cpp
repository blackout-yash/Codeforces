// C. Save More Mice
// Link - https://codeforces.com/contest/1593/problem/C



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
		int k, n, count = 0, prev = 0;
		cin >> k >> n;
		int x[n];
		fora(i, 0, n) cin >> x[i];
		sort(x, x + n, greater <int> ());

		fora(i, 0, n) {
			if (prev < x[i]) count++;
			else break;
			prev += (k - x[i]);
		} cout << count << "\n";
	}

	return 0;
}