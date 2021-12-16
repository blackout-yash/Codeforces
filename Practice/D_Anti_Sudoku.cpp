// D. Anti-Sudoku
// Link - https://codeforces.com/problemset/problem/1335/D



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
		string s[9];
		fora(i, 0, 9) cin >> s[i];

		int que, rem, temp;
		fora(i, 0, 9) {
			que = i / 3;

			rem = (i + 1) % 3;

			if (rem == 0) temp = 9 - (que + 1);
			else if (rem == 1) temp = 3 - (que + 1);
			else temp = 6 - (que + 1);

			char ch = s[i][temp];

			if (i > 5) s[i][temp + 2] = ch;
			else s[i][temp - 1] = ch;
		}

		fora(i, 0, 9) cout << s[i] << "\n";
	}

	return 0;
}