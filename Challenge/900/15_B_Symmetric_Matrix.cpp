// B. Symmetric Matrix
// Link - https://codeforces.com/problemset/problem/1426/B



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

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;

		bool flag = false;
		int a, b, c, d;
		while (n--) {
			cin >> a >> b >> c >> d;
			if (b == c) flag = true;
		}

		if (m & 1) cout << "NO\n";
		else if (flag) cout << "YES\n";
		else cout << "NO\n";
	}
	return 0;
}