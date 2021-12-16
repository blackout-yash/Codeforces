// B. M-arrays
// Link - https://codeforces.com/contest/1497/problem/B



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
		vector <vector <int>> ans(k);
		fora(i, 0, n) {
			int x; cin >> x;
			int rem = x % k;
			ans[rem].push_back(x);
		}

		int res = 0, i = 1, j = k - 1;
		if (ans[0].size()) res++;

		while (i <= j) {
			int size1 = ans[i].size(), size2 = ans[j].size();
			if (i == j && size1) res++;
			else {
				int minimum = min(size1, size2), maximum = max(size1, size2);
				if (minimum > 0) {
					res++; maximum--;
				}
				int temp = maximum - minimum;
				if (temp > 0) res += temp;
			} i++; j--;
		}
		cout << res << "\n";
	}

	return 0;
}