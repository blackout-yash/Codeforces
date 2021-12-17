// B. Shooting
// Link - https://codeforces.com/problemset/problem/1216/B



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

	int n;
	cin >> n;
	vector <pair <int, int>> v;
	fora(i, 0, n) {
		int x; cin >> x;
		v.pb(mp(x, i + 1));
	} sort(v.begin(), v.end());

	int ans = 0, x = 0;
	vector <int> temp;
	rfora(i, 0, n) {
		ans += (x * v[i].first) + 1;
		x++;
		temp.pb(v[i].second);
	} cout << ans nline;
	for (auto x : temp) cout << x << " ";

	return 0;
}