// B. Swaps
// https://codeforces.com/problemset/problem/1573/B



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
		int odd[n], even[n];
		map <int, int> m;
		fora(i, 0, n) cin >> odd[i];
		fora(i, 0, n) {
			cin >> even[i];
			m[even[i]] = i;
		}

		int prev;
		for (auto it = m.rbegin(); it != m.rend(); it++) {
			if (it == m.rbegin()) prev = it->second;
			else {
				if (it -> second >  prev) it->second = prev;
				else prev = it->second;
			}
		}

		int minimum = n - 1;
		fora(i, 0, n) {
			int temp = i + m[odd[i] + 1];
			minimum = min(minimum, temp);
		} cout << minimum << "\n";

	}

	return 0;
}