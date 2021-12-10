// C. Two Arrays
// Link - https://codeforces.com/problemset/problem/1584/C



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
		int n;
		cin >> n;
		vector <int> a(n), b(n);
		fora(i, 0, n) cin >> a[i];
		fora(i, 0, n) cin >> b[i];
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		bool flag = true;
		fora(i, 0, n) {
			int diff = b[i] - a[i];
			if (diff == 0 || diff == 1) {}
			else {flag = false; break;}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}