// B. Napoleon Cake
// Link - https://codeforces.com/contest/1501/problem/B



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
		int arr[n];
		fora(i, 0, n) cin >> arr[i];

		int ans[n], temp = 0;
		for (int i = n - 1; i >= 0; i--) {
			temp = max(temp, arr[i]);
			if (temp) {
				ans[i] = 1;
				temp--;
			} else ans[i] = 0;
		}

		fora(i, 0, n) cout << ans[i] << " ";
		cout << "\n";
	}

	return 0;
}