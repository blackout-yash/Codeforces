// B. The Great Hero
// Link - https://codeforces.com/contest/1480/problem/B



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
		int attack, health, n;
		cin >> attack >> health >> n;
		int a[n], b[n];
		fora(i, 0, n) cin >> a[i];
		fora(i, 0, n) cin >> b[i];
		vector <pair <int, int>> v;
		fora(i, 0, n) v.pb(mp(a[i], b[i]));
		sort(v.begin(), v.end());

		int ans = 0, index = -1, store;
		bool flag = true;
		fora(i, 0, n) {
			int count = ceil(double(v[i].second) / attack);
			ans += (count * v[i].first);
			if (ans >= health) {
				index = i; flag = false;
				break;
			}
		}

		if (health >= ans && flag) cout << "YES\n";
		else if (index == n - 1 && ans - v[n - 1].first < health) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}