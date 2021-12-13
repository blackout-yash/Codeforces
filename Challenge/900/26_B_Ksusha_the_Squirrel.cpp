// B. Ksusha the Squirrel
// Link - https://codeforces.com/problemset/problem/299/B



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

	int n, k, temp = 0; string s;
	cin >> n >> k >> s;

	bool flag = true;
	fora(i, 0, n) {
		if (s[i] == '.') temp = 0;
		else temp++;
		if (temp >= k) {
			flag = false;
			break;
		}
	}

	if (flag) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}