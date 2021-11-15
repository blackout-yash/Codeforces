// A. Meximization
// Link - https://codeforces.com/contest/1497/problem/A



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
		int n, prev;
		cin >> n;
		vector <int> v(n);
		fora(i, 0, n) cin >> v[i];
		sort(v.begin(), v.end());

		vector <int> store;
		while (v.size()) {
			fora(i, 0, v.size()) {
				if (!i) {
					cout << v[i] << " ";
					prev = v[i];
					store.push_back(i);
				} else {
					if (prev != v[i]) {
						cout << v[i] << " ";
						prev = v[i];
						store.push_back(i);
					}
				}
			}
			int temp = 0;
			for (auto x : store) {
				v.erase(v.begin() + (x - temp));
				temp++;
			}
			store.clear();
		} cout << "\n";
	}

	return 0;
}