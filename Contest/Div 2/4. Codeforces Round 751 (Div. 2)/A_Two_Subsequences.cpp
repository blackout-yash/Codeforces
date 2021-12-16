// A. Two Subsequences
// Link - https://codeforces.com/contest/1602/problem/A



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
		string s;
		cin >> s;

		int minimum = INT_MAX;
		fora(i, 0, s.size()) {
			minimum = min(minimum, (int)s[i]);
		}
		char c = char(minimum);

		cout << c << " ";
		bool flag = true;
		fora(i, 0, s.size()) {
			if (flag && s[i] == c) flag = false;
			else cout << s[i];
		} cout << "\n";
	}

	return 0;
}