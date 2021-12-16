// B. Maximum Cost Deletion
// Link - https://codeforces.com/problemset/problem/1550/B



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
		int n, a, b; string s;
		cin >> n >> a >> b >> s;

		int one = 0, zero = 0;
		vector <int> v;
		fora(i, 0, n) {
			if (s[i] == '1') one++;
			else zero++;

			if (one && zero) {
				if (one == zero) {
					if (s[i - 1] == '0') {
						v.push_back(zero);
						zero = 0;
					} else {
						v.push_back(one);
						one = 0;
					}
				}
				else if (one == 1) {
					v.push_back(zero);
					zero = 0;
				} else if (zero == 1) {
					v.push_back(one);
					one = 0;
				}
			}
			if (i + 1 == n) {
				if (one) v.push_back(one);
				if (zero) v.push_back(zero);
			}
		}

		int res1 = 0, res2 = 0, res3 = 0, count = 0;
		for (auto x : v) {
			int ans1 = (x * a) + b;
			int ans2 = x * (a + b);
			res1 += max(ans1, ans2);
		}
		for (int i = 0; i < v.size(); i += 2) {
			count += v[i];
			int ans1 = (v[i] * a) + b;
			int ans2 = v[i] * (a + b);
			res2 += max(ans1, ans2);
		} if (n - count) res2 += max((((n - count) * a) + b), (n - count) * (a + b));

		count = 0;
		for (int i = 1; i < v.size(); i += 2) {
			count += v[i];
			int ans1 = (v[i] * a) + b;
			int ans2 = v[i] * (a + b);
			res3 += max(ans1, ans2);
		} if (n - count) res3 += max((((n - count) * a) + b), (n - count) * (a + b));

		cout << max(res1, max(res2, res3)) << "\n";
	}

	return 0;
}