// B. Non-Substring Subsequence
// Link - https://codeforces.com/problemset/problem/1451/B



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

bool solve(string &s, string &temp, bool flag, int i, int j, vector <vector <int>> &dp) {
	if (i == 0) {
		if (flag) return true;
		return false;
	} else if (j == 0) return false;
	else if (dp[i][j] != -1) return dp[i][j];

	int ans1 = false, ans2 = false;

	if (temp[i - 1] == s[j - 1]) ans1 = solve(s, temp, flag, i - 1, j - 1, dp);
	rfora(k, 0, j - 1) {
		if (temp[i - 1] == s[k]) {
			if (temp.size() != i) ans2 = solve(s, temp, true, i - 1, k, dp);
			else ans2 = solve(s, temp, false, i - 1, k, dp);
			break;
		}
	}

	if (ans1 || ans2) return dp[i][j] = true;
	return dp[i][j] = false;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, q, l, r;
		string s;
		cin >> n >> q >> s;
		while (q--) {
			cin >> l >> r;
			int start = l - 1, size = r - (l - 1);
			string temp = s.substr(start, size);
			vector <vector <int>> dp(size + 1, vector <int> (n + 1, -1));
			if (solve(s, temp, false, size, n, dp)) cout << "YES" nline;
			else cout << "NO" nline;
		}
	}
	return 0;
}