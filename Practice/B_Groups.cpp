// B. Groups
// Link - https://codeforces.com/contest/1598/problem/B



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
		int n;
		cin >> n;

		vector <vector <int>> ans(5);
		fora(i, 0, n) {
			fora(j, 0, 5) {
				int x; cin >> x;
				if (x) ans[j].push_back(i + 1);
			}
		}

		bool flag = false;
		fora(i, 0, 5) {
			fora(j, i + 1, 5) {
				if (ans[i].size() >= n / 2 && ans[j].size() >= n / 2) {
					set <int> s;
					for (auto x : ans[i]) s.insert(x);
					for (auto x : ans[j]) s.insert(x);
					if (s.size() == n) {
						flag = true;
						break;
					}
				}
			} if (flag) break;
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}