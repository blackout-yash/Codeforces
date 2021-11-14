// A. Split it!
// Link - https://codeforces.com/contest/1496/problem/A



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
		int n, k; string s;
		cin >> n >> k >> s;

		if (!k) cout << "YES\n";
		else {
			int count = 0;
			int i = 0, j = s.size() - 1;
			while (i <= j) {
				if (s[i] != s[j]) {count++; break;}
				count++; i++; j--;
			}

			if (count > k) cout << "YES\n";
			else cout << "NO\n";
		}
	}

	return 0;
}