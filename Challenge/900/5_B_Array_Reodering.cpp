// B. Array Reodering
// Link - https://codeforces.com/problemset/problem/1535/B



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

int _gcd (int a, int b) {
	return b ? _gcd (b, a % b) : a;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, count = 0;
		cin >> n;
		vector <int> arr(n);
		fora(i, 0, n) cin >> arr[i];

		fora(i, 0, n) {
			fora(j, i + 1, n) {
				int gcd1 = _gcd(2 * arr[i], arr[j]), gcd2 = _gcd(arr[i], 2 * arr[j]);
				if (gcd1 > 1 || gcd2 > 1) count++;
			}
		} cout << count << "\n";
	}

	return 0;
}