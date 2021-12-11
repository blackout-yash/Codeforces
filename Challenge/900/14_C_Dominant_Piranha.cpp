// C. Dominant Piranha
// Link - https://codeforces.com/problemset/problem/1433/C



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b) for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n"
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int arr[n], minimum = INT_MAX, maximum = INT_MIN;
		fora(i, 0, n) {
			cin >> arr[i];
			minimum = min(minimum, arr[i]);
			maximum = max(maximum, arr[i]);
		}

		if (minimum == maximum) cout << "-1\n";
		else {
			int index = -1;
			fora(i, 1, n) {
				if (arr[i] == maximum && arr[i - 1] != maximum) {
					index = i + 1;
					break;
				}
			}

			if (index == -1) {
				fora(i, 0, n - 1) {
					if (arr[i] == maximum && arr[i + 1] != maximum) {
						index = i + 1;
						break;
					}
				}
			} cout << index nline;
		}
	}

	return 0;
}