// B. Divan and a New Project
// Link - https://codeforces.com/contest/1614/problem/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n"
#define size(x) (x).size()
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <pair <int, int>> v;
		vector <int> ans(n + 1), store; ans[0] = -1;
		fora(i, 0, n) {
			int x; cin >> x;
			store.pb(x);
			v.pb(mp(x, i));
		} sort(v.begin(), v.end());

		int low = -2, high = 0;
		rfora(i, 0, n) {
			if (i & 1) ans[v[i].second + 1] = high++;
			else ans[v[i].second + 1] = low--;
		}
		int sum = 0, i = 0;
		for (auto x : ans) {
			if (x != -1)sum += (2 * store[i++]) * abs(-1 - x);
		}
		cout << sum nline;
		for (auto x : ans) cout << x << " ";
		cout nline;
	}

	return 0;
}