// C. MAX-MEX Cut
// Link - https://codeforces.com/problemset/problem/1566/C



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

int mex(int min, int max) {
	if (min == max) {
		if (min) return 0;
		return 1;
	} else if (min) return 0;
	else if (max == 1) return 2;
	return 1;
}

int solve(int a[], int b[], int n, int dp[]) {
	if (n == 0) return 0;
	else if (dp[n] != -1) return dp[n];

	int minimum1 = min(a[n - 1], b[n - 1]), maximum1 = max(a[n - 1], b[n - 1]);
	int mex1 = 0, mex2 = 0, mex3 = 0;

	mex1 = mex(minimum1, maximum1) + solve(a, b, n - 1, dp);
	if (n > 1) {
		int minimum2 = min(a[n - 2], b[n - 2]), maximum2 = max(a[n - 2], b[n - 2]);
		int minimum3 = min(minimum1, minimum2), maximum3 = max(maximum1, maximum2);
		mex3 = mex(minimum3, maximum3) + solve(a, b, n - 2, dp);
	}

	return dp[n] = max(mex1, mex3);
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n], b[n];
		fora(i, 0, n) {
			char c; cin >> c;
			a[i] = int32_t(c - '0');
		}
		fora(i, 0, n) {
			char c; cin >> c;
			b[i] = int32_t(c - '0');
		}

		int dp[n + 1];
		memset(dp, -1, sizeof(dp));
		cout << solve(a, b, n, dp) nline;
	}

	return 0;
}