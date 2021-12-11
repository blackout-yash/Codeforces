// B. Kana and Dragon Quest game
// Link - https://codeforces.com/problemset/problem/1337/B



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

int solve(int x, int n, int m, vector <vector <int>> &dp) {
	if (x <= 0) return true;
	else if (!n && !m) return false;
	else if (dp[n][m] != -1) return dp[n][m];

	int ans1 = false, ans2 = false;
	if (n) ans1 = solve((x / 2) + 10, n - 1, m, dp);
	if (m) ans2 = solve(x - 10, n, m - 1, dp);

	if (ans1 || ans2) return dp[n][m] = true;
	return dp[n][m] = false;
}


int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int x, n, m;
		cin >> x >> n >> m;
		vector <vector <int>> dp(n + 1, vector <int> (m + 1, -1));
		if (solve(x, n, m, dp))cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}