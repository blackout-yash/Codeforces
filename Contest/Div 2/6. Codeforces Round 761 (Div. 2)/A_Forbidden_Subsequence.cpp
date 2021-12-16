// A. Forbidden Subsequence
// Link - https://codeforces.com/contest/1617/problem/A



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
		string s, t;
		cin >> s >> t;
		map <char, string> m1, m2;
		bool flag = false;
		fora(i, 0, s.size()) m1[s[i]] += s[i];
		fora(i, 0, t.size()) {
			if (i) {
				if (t[i - 1] > t[i]) flag = true;
			}
			m2[t[i]] += t[i];
		}

		if (flag) {
			for (auto x : m1) cout << x.second;
			cout nline;
		} else {
			flag = false;
			for (auto x : m2) {
				char c = x.second[0];
				int size = x.second.size();
				if (size > m1[c].size()) {
					flag = true; break;
				}
			}

			if (flag) {
				for (auto x : m1) cout << x.second;
				cout nline;
			} else {
				char c1, c2; flag = true;
				rfora(i, 0, 3) {
					if (flag) {
						c1 = t[i]; flag = false;
					} else if (!flag && t[i] != c1) {
						c2 = t[i]; break;
					}
				}

				string store1 = m1[c1], store2 = m1[c2];
				flag = true;
				for (auto x : m1) {
					if (x.second[0] == c1) cout << store2;
					else if (x.second[0] == c2) cout << store1;
					else cout << x.second;
				} cout nline;
			}
		}
	}

	return 0;
}