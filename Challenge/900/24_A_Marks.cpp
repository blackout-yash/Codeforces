// A. Marks
// Link - https://codeforces.com/problemset/problem/152/A



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

	int n, m;
	cin >> n >> m;
	string s[n];
	fora(i, 0, n) cin >> s[i];

	int maximum[m]; memset(maximum, 0, sizeof(maximum));
	fora(i, 0, m) {
		fora(j, 0, n) {
			int temp = int32_t(s[j][i] - '0');
			maximum[i] = max(maximum[i], temp);
		}
	}

	int ans = 0;
	fora(i, 0, n) {
		fora(j, 0, m) {
			int temp = int32_t(s[i][j] - '0');
			if (temp == maximum[j]) {
				ans++; break;
			}
		}
	} cout << ans nline;

	return 0;
}