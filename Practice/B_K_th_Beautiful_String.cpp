// B. K-th Beautiful String
// Link - https://codeforces.com/problemset/problem/1328/B



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
		int n, k;
		cin >> n >> k;

		float temp = (-1 + sqrt(1 + 8 * k)) / 2;
		int term = ceil(temp), rem = k - (term * (term - 1)) / 2;

		fora(i, 0, n) {
			if (i + 1 == (n - term) || i + rem == n) cout << "b";
			else cout << "a";
		} cout << "\n";
	}

	return 0;
}