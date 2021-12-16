// D1. All are Same
// Link - https://codeforces.com/contest/1593/problem/D1



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(int i=a;i<b;i++)

int gcd (int a, int b) {
	return b ? gcd (b, a % b) : a;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, minimum = INT_MAX;
		cin >> n;
		int arr[n];
		fora(i, 0, n) {
			cin >> arr[i];
			minimum = min(minimum, arr[i]);
		}

		set <int> s;
		fora(i, 0, n) {
			if (arr[i] != minimum) s.insert(arr[i] - minimum);
		} vector <int> v(s.begin(), s.end());

		if (v.empty()) cout << "-1\n";
		else {
			int prev = v[0];
			fora(i, 0, v.size()) {
				prev = gcd(prev, v[i]);
			} cout << prev << "\n";
		}
	}
	return 0;
}