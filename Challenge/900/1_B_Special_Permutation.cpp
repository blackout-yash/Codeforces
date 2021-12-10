// B. Special Permutation
// Link - https://codeforces.com/problemset/problem/1612/B



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

	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;

		vector <int> left, right;
		left.pb(a);

		int temp = n;
		while (left.size() != n / 2) {
			if (temp == a) break;
			if (temp != b) left.pb(temp--);
			else temp--;
		}

		rfora(i, 1, b + 1) {
			auto it = find(left.begin(), left.end(), i);
			if (it == left.end()) right.pb(i);
		}

		if (left.size() == n / 2 && right.size() == n / 2) {
			for (auto x : left) cout << x << " ";
			for (auto x : right) cout << x << " ";
			cout nline;
		} else cout << "-1" nline;
	}

	return 0;
}