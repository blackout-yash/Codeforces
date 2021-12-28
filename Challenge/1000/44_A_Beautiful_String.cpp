// A. Beautiful String
// Link - https://codeforces.com/problemset/problem/1265/A



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

bool find(string &s, char c) {
	fora(i, 0, size(s)) {
		if (s[i] == c) return false;
	} return true;
}

int32_t main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		int n = size(s), start = 0;
		fora(i, 0, n) {
			if (s[i] == '?') {
				if (s[i + 1] != '?') {
					string temp;
					if (i) temp.pb(s[i - 1]);
					if (i + 1 != n)temp.pb(s[i + 1]);
					if (find(temp, 'a')) start = 0;
					else if (find(temp, 'b')) start = 1;
					else start = 2;
				}
				s[i] = char('a' + start);
				start++;
				if (start == 3) start = 0;
			} else {
				if (s[i] == 'a') start = 1;
				else if (s[i] == 'b') start = 2;
				else start = 0;
			}
		}

		bool flag = true;
		fora(i, 0, n) {
			if (s[i] == s[i - 1]) {
				flag = false; break;
			}
		}

		if (flag) cout << s nline;
		else cout << "-1\n";
	}

	return 0;
}