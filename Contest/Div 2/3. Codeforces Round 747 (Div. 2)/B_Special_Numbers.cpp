// B. Special Numbers
// Link - https://codeforces.com/contest/1594/problem/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fora(i,a,b) for(ll i=a;i<b;i++)
const int mod = 1e9 + 7;

int power(int x, int y, int p = 1e9 + 7) {
	int res = 1;
	x = x % p;

	if (x == 0) return 0;

	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;
		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector <int> v;
	int temp = 0, i = 0;
	while (temp <= 1e9) {
		temp += (1 << i);
		v.push_back(temp);
		i++;
	}

	int t;
	cin >> t;
	while (t--) {
		int n, k, ans = 0;
		cin >> n >> k;

		while (k > 0) {
			auto it = lower_bound(v.begin(), v.end(), k);
			int index = it - v.begin();
			ans += power(n, index) % mod;
			k -= (1 << index);
		} cout << ans % mod << "\n";
	}

	return 0;
}