// A. Happy Birthday, Polycarp!
// Link - https://codeforces.com/problemset/problem/1277/A



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
		string s;
		cin >> s;
		int n = size(s), ans = (n - 1) * 9;
		fora(i, 0, 9) {
			char c = '1' + i;
			string temp(n, c);
			if (s >= temp) ans++;
			else break;
		} cout << ans nline;
	}

	return 0;
}