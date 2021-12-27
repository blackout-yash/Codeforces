// A. Shuffle Hashing
// Link - https://codeforces.com/problemset/problem/1278/A



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
		string s, h;
		cin >> s >> h;
		sort(s.begin(), s.end());

		int n1 = size(s), n2 = size(h);
		bool flag = false;
		fora(i, 0, (n2 + 1) - n1) {
			string temp = h.substr(i, n1);
			sort(temp.begin(), temp.end());
			if (s == temp) {
				flag = true;
				break;
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}