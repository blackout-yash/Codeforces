// C. Di-visible Confusion
// Link - https://codeforces.com/contest/1604/problem/C



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
		int n, x;
		cin >> n;

		vector <int> v(n);
		fora(i, 0, n) cin >> v[i];

		for (int i = v.size() - 1; i >= 0; i--) {
			if (v[i] % (i + 2) != 0) {
				v.erase(v.begin() + i);
				i = v.size();
			}
		}

		if (v.size() == 0) cout << "YES\n";
		else cout << "NO\n";
	}


	return 0;
}