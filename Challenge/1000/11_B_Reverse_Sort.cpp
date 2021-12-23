// B. Reverse Sort
// Link - https://codeforces.com/contest/1605/problem/B



#include <bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define mp make_pair
#define fora(i,a,b)  for(int i=a;i<b;i++)
#define rfora(i,a,b) for(int i=b-1;i>=a;i--)
#define nline << "\n"
#define size(x) (x).size()
const int mod = 1e9 + 7;
/*-----------------------------------------------------------------------------------*/

bool isCheck(string &s) {
	bool flag = false;
	rfora(i, 0, size(s)) {
		if (s[i] == '0') flag = true;
		if (flag && s[i] == '1') return false;
	}
	return true;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, count = 0; string s;
		cin >> n >> s;
		vector <vector <int>> ans;
		fora(i, 0, n) {
			if (s[i] == '1') count++;
		}

		while (true) {
			if (isCheck(s)) break;
			vector <int> one, zero, temp;

			bool flag = true;
			rfora(i, 0, size(s)) {
				if (s[i] == '0') {
					if (flag) zero.pb(i);
				} else {
					if (size(zero)) flag = false;
					if (!flag && i < (n - count)) one.pb(i);
					if (!size(one)) flag = true;
				}
			} sort(one.begin(), one.end());
			sort(zero.begin(), zero.end());

			int j = size(zero) - 1;
			fora(i, 0, min(size(zero), size(one))) {
				swap(s[one[i]], s[zero[j--]]);
				temp.pb(one[i]);
			}

			j = size(zero) - min(size(zero), size(one));
			fora(i, 0, min(size(zero), size(one))) temp.pb(zero[j++]);

			if (size(temp)) ans.pb(temp);
		}

		cout << size(ans) nline;
		if (size(ans)) {
			fora(i, 0, size(ans)) {
				cout << size(ans[0]) << " ";
				fora(j, 0, size(ans[i])) cout << ans[i][j] + 1 << " ";
				cout nline;
			}
		}
	}

	return 0;
}