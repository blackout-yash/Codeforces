// C. Array Elimination
// Link - https://codeforces.com/contest/1602/problem/C



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

		int binary[30] = {0};
		fora(i, 0, n) {
			int temp = arr[i];

			int binaryNum[30], j = 0;
			while (temp > 0) {
				binaryNum[j] = temp % 2;
				temp /= 2;
				j++;
			}

			for (int k = j - 1; k >= 0; k--) if (binaryNum[k]) binary[k]++;
		}

		bool ans[n];
		memset(ans, 1, sizeof(ans));

		fora(i, 0, n) {
			fora(j, 0, 30) {
				if (binary[j] != 0 && (binary[j] % (i + 1)) != 0) {
					ans[i] = false;
					break;
				}
			}
		}

		fora(i, 0, n) {
			if (ans[i]) cout << i + 1 << " ";
		} cout << "\n";

	}

	return 0;
}