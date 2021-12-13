// B. Burglar and Matches
// Link - https://codeforces.com/problemset/problem/16/B



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

	int n, m, ans = 0;
	cin >> n >> m;
	vector <pair <int, int>> v;
	fora(i, 0, m) {
		int a, b;
		cin >> a >> b;
		v.pb(mp(b, a));
	} sort(v.begin(), v.end());

	rfora(i, 0, m) {
		if (n == 0) break;
		if (v[i].second >= n) {
			ans += (v[i].first * n); n = 0;
		} else {
			n -= v[i].second; ans += (v[i].first * v[i].second);
		}
	} cout << ans nline;

	return 0;
}