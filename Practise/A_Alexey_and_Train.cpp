// A. Alexey and Train
// Link - https://codeforces.com/contest/1501/problem/A



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
		int n;
		cin >> n;

		int a[n], b[n], c[n], d[n], delay[n];
		fora(i, 0, n) {
			cin >> a[i] >> b[i];
			c[i] = a[i]; d[i] = b[i];
		}
		fora(i, 0, n) cin >> delay[i];

		int ans = 0;
		fora(i, 0, n) {
			int temp = ceil(double(b[i] - a[i]) / 2);
			c[i] += delay[i];
			int diff = (d[i] - c[i]);
			if (temp > diff && i + 1 != n) c[i + 1] += (temp - diff);
		}
		cout << c[n - 1] << "\n";
	}
	return 0;
}