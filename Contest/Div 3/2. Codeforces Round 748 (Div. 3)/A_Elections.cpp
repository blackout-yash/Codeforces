// A. Elections
// Link - https://codeforces.com/contest/1593/problem/A



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
		int a, b, c;
		cin >> a >> b >> c;
		if (a >= max(b, c) + 1) cout << 0 << " ";
		else cout << max(b, c) + 1 - a << " ";

		if (b >= max(a, c) + 1) cout << 0 << " ";
		else cout << max(a, c) + 1 - b << " ";

		if (c >= max(a, b) + 1) cout << 0 << "\n";
		else cout << max(a, b) + 1 - c << "\n";

	}

	return 0;
}