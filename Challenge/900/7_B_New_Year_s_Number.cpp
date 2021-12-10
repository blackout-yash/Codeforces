// B. New Year's Number
// Link - https://codeforces.com/problemset/problem/1475/B



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

bool solve(int n, vector <int> &dp) {
	if (n == 0) return true;
	else if (dp[n] != -1) return dp[n];

	bool ans1 = false, ans2 = false;
	if (n >= 2020) ans1 = solve(n - 2020, dp);
	if (n >= 2021) ans2 = solve(n - 2021, dp);

	if (ans1 || ans2) return dp[n] = true;
	return dp[n] = false;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	vector <int> dp((1e6) + 1, -1);
	while (t--) {
		int n;
		cin >> n;
		if (solve(n, dp)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}