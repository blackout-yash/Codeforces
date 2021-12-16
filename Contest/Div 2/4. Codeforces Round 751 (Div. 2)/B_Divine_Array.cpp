// B. Divine Array
// Link - https://codeforces.com/contest/1602/problem/B



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
		vector <vector <int>> v; vector <int> temp;
		fora(i, 0, n) {
			int x; cin >> x;
			temp.push_back(x);
		}
		v.push_back(temp);
		temp.clear();

		map <int, int> m; bool flag = true;
		int prev = 0;
		while (flag) {
			for (auto x : v[prev]) m[x]++;

			flag = false;
			for (auto it = m.begin(); it != m.end(); it++) {
				if (it->first != it->second) {
					flag = true;
					break;
				}
			}

			if (flag) {
				fora(i, 0, n) {
					temp.push_back(m[v[prev][i]]);
				}

				v.push_back(temp);
				temp.clear();
				m.clear();
				prev++;
			}
		}

		int q, x, k;
		cin >> q;
		while (q--) {
			cin >> x >> k;
			if (k > prev) k = prev;
			cout << v[k][x - 1] << "\n";
		}
	}
	return 0;
}