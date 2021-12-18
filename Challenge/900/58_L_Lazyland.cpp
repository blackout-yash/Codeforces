// L. Lazyland
// Link - https://codeforces.com/problemset/problem/1089/L



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

	int n, k;
	cin >> n >> k;
	int a[n], b[n];
	fora(i, 0, n) cin >> a[i];
	fora(i, 0, n) cin >> b[i];

	map <int, vector <int>> m;
	bool flag[k + 1];
	memset(flag, true, sizeof(flag));
	fora(i, 0, n) {
		flag[a[i]] = false;
		m[a[i]].pb(b[i]);
	}

	vector <int> temp;
	for (auto x : m) {
		if (x.second.size() > 1) {
			sort(x.second.begin(), x.second.end());
			fora(i, 0, x.second.size() - 1) temp.pb(x.second[i]);
		}
	} sort(temp.begin(), temp.end());

	int sum = 0, j = 0;
	fora(i, 1, k + 1) {
		if (flag[i]) sum += temp[j++];
	} cout << sum;

	return 0;
}