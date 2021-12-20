// A. Wizard of Orz
// Link - https://codeforces.com/problemset/problem/1467/A



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

	int t;
	cin >> t;
	while (t--) {
		int n, range = 0;
		cin >> n;

		string s = "989";
		if (n <= 3) cout << s.substr(0, n) nline;
		else {
			n -= 3;
			cout << s;
			while (n--) {
				cout << range++;
				if (range == 10) range = 0;
			} cout nline;
		}
	}

	return 0;
}