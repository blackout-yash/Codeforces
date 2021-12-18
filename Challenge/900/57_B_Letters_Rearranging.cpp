// B. Letters Rearranging
// Link - https://codeforces.com/problemset/problem/1093/B



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

bool isPalidrome(string &s) {
	int i = 0, j = s.size() - 1;
	while (i <= j) {
		if (s[i++] != s[j--]) return false;
	}

	return true;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;

		if (s.size() <= 1) cout << "-1\n";
		else if (!isPalidrome(s)) cout << s nline;
		else {
			bool flag = true;
			fora(i, 1, s.size()) {
				if (s[i] != s[i - 1]) {
					swap(s[i], s[i - 1]);
					flag = false; break;
				}
			}
			if (flag) cout << "-1\n";
			else cout << s nline;
		}
	}

	return 0;
}