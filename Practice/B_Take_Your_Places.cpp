// B. Take Your Places!
// https://codeforces.com/contest/1556/problem/B



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
		int n, o, e;
		vector <int> odd, even;
		cin >> n;
		int arr[n];
		fora(i, 0, n) {
			cin >> arr[i];
			if (arr[i] & 1) odd.push_back(i);
			else even.push_back(i);
		} o = odd.size(); e = even.size();

		if (abs(o - e) > 1) cout << "-1\n";
		else {
			int ans1 = 0, i = 0;
			for (auto x : even) {
				ans1 += abs(x - i);
				i += 2;
			}
			int ans2 = 0; i = 1;
			for (auto x : even) {
				ans2 += abs(x - i);
				i += 2;
			}

			int ans3 = 0; i = 0;
			for (auto x : odd) {
				ans3 += abs(x - i);
				i += 2;
			}
			int ans4 = 0; i = 1;
			for (auto x : odd) {
				ans4 += abs(x - i);
				i += 2;
			}

			int minimum1 = min(ans1, ans2), minimum2 = min(ans3, ans4);

			if (minimum1 == minimum2) cout << min(ans1, ans2) << "\n";
			else cout << min(max(ans1, ans2), max(ans3, ans4)) << "\n";
		}
	}

	return 0;
}