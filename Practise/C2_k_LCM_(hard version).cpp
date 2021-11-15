// C2. k-LCM (hard version)
// Link - https://codeforces.com/contest/1497/problem/C2



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

		fora(i, 0, k - 3) {
			cout << "1 ";
			n--;
		}

		if (n & 1) {
			n--;
			cout << 1 << " " << n / 2 << " " << n / 2 << "\n";
		} else {
			if ((n - 2) % 4 == 0) cout << 2 << " " << (n - 2) / 2 << " " << (n - 2) / 2 << "\n";
			else cout << n / 4 << " " << n / 4 << " " << n / 2 << "\n";
		}
	}

	return 0;
}