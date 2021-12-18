// B. Equalize Prices
// Link - https://codeforces.com/problemset/problem/1183/B



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
		int n, k, x, maximum = INT_MIN, minimum = INT_MAX;
		cin >> n >> k;
		int arr[n];
		fora(i, 0, n) {
			cin >> arr[i];
			maximum = max(maximum, arr[i]);
			minimum = min(minimum, arr[i]);
		} x = minimum + k;

		if (abs(maximum - x) > k) cout << "-1\n";
		else cout << x nline;
	}

	return 0;
}