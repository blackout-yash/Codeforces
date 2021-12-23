// A. Regular Bracket Sequence
// Link - https://codeforces.com/problemset/problem/1469/A



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n"
#define size(x) (x).size()
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

bool solve(string &s, int i, int count, vector <vector <int>> &dp) {
	if (size(s) == i) {
		if (count) return false;
		return true;
	} else if (count < 0) return 0;
	else if (dp[i][count] != -1) return dp[i][count];

	bool ans1 = false, ans2 = false;
	if (s[i] == '(') ans1 = solve(s, i + 1, count + 1, dp);
	else if (s[i] == ')') ans2 = solve(s, i + 1, count - 1, dp);
	else {
		ans1 = solve(s, i + 1, count + 1, dp);
		ans2 = solve(s, i + 1, count - 1, dp);
	}

	if (ans1 || ans2) return dp[i][count] = true;
	return dp[i][count] = false;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = size(s);
		if (n & 1) cout << "NO\n";
		else {
			vector <vector <int>> dp(n + 1, vector <int> (n + 1, -1));
			if (solve(s, 0, 0, dp)) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}