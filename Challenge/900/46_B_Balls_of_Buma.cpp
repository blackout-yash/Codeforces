// B. Balls of Buma
// Link - https://codeforces.com/contest/1267/problem/B



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

bool check(vector <pair <char, int>> v, int index) {
	int i = index - 1, j = index + 1;
	while (i >= 0 && j < v.size()) {
		if (v[i].first != v[j].first) return false;
		else {
			if (v[i].second + v[j].second < 3) return false;
			else {
				i--; j++;
			}
		}
	}
	if (i == -1 && j == v.size()) return true;
	return false;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s;
	cin >> s;
	vector <pair <char, int>> v;
	int prev = 1;
	fora(i, 0, s.size()) {
		if (i) {
			if (s[i - 1] == s[i]) prev++;
			else {
				v.pb(mp(s[i - 1], prev));
				prev = 1;
			}
		}

		if (i + 1 == s.size()) v.pb(mp(s[i], prev));
	}

	if (v.size() <= 2 || !(v.size() & 1)) cout << "0";
	else {
		bool flag = true; int ans = 0;
		fora(i, 1, v.size() - 1) {
			if (v[i].second > 1 && check(v, i)) {
				ans += (v[i].second + 1);
				flag = false;
			}
		} if (flag) cout << "0";
		else cout << ans;
	}

	return 0;
}