// B. Max and Mex
// Link - https://codeforces.com/contest/1496/problem/B



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

		int arr[n], maximum = 0, mex = -1;
		set <int> s;
		fora(i, 0, n) {
			cin >> arr[i];
			s.insert(arr[i]);
			maximum = max(maximum, arr[i]);
		}

		int i = 0;
		for (auto x : s) {
			if (i != x) {
				mex = i;
				break;
			} else i++;
		}

		if (mex == -1) cout << (n + k) << "\n";
		else {
			if (k) s.insert(ceil(double(mex + maximum) / 2));
			cout << s.size() << "\n";
		}
	}

	return 0;
}