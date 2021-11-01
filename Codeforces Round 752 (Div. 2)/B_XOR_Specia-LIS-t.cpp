// B. XOR Specia-LIS-t
// Link - https://codeforces.com/contest/1604/problem/B



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
		int arr[n]; bool flag = false;
		fora(i, 0, n) {
			cin >> arr[i];
			if (i && !flag) {
				if (arr[i - 1] >= arr[i]) flag = true;
			}
		}

		if (n & 1) {
			if (flag) cout << "YES\n";
			else cout << "NO\n";
		} else cout << "YES\n";
	}


	return 0;
}