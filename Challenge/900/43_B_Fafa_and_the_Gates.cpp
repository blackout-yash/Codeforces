// B. Fafa and the Gates
// Link - https://codeforces.com/problemset/problem/935/B



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

	int n; string s;
	cin >> n >> s;

	int x = 0, y = 0, ans = 0;
	bool flag = true;
	fora(i, 0, n) {
		if (s[i] == 'U') x++;
		else if (s[i] == 'D') x--;
		else if (s[i] == 'R') y++;
		else y--;

		if (!i) {
			if (y > x) flag = false;
		} else if (flag && x < y) {
			ans++; flag = false;
		} else if (!flag && x > y) {
			ans++; flag = true;
		}
	} cout << ans;

	return 0;
}