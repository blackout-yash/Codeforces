// B1. Character Swap (Easy Version)
// Link - https://codeforces.com/problemset/problem/1243/B1



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
		int n, count = 0; string s, t;
		cin >> n >> s >> t;

		map <char, int> ms, mt;
		fora(i, 0, n) {
			if (s[i] != t[i]) {
				ms[s[i]]++; mt[t[i]]++;
				count++;
			}
		}

		if (size(ms) == size(mt)) {
			if (!size(ms)) cout << "YES\n";
			else if (size(ms) == 1 && count == 2) cout << "YES\n";
			else cout << "NO\n";
		} else cout << "NO\n";
	}

	return 0;
}