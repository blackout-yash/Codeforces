// B. Tiling Challenge
// Link - https://codeforces.com/problemset/problem/1150/B



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

	int n;
	cin >> n;
	char s[n][n];
	fora(i, 0, n) {
		fora(j, 0, n) {
			cin >> s[i][j];
		}
	}

	bool flag = true;
	fora(i, 0, n) {
		fora(j, 0, n) {
			if (s[i][j] == '.') {
				if (j == 0 || j + 1 == n || i + 2 >= n) {
					flag = false; break;
				} else if (s[i + 1][j] == '#' || s[i + 2][j] == '#' || s[i + 1][j - 1] == '#' || s[i + 1][j + 1] == '#') {
					flag = false; break;
				} else {
					s[i + 1][j] = '#'; s[i + 2][j] = '#'; s[i + 1][j - 1] = '#'; s[i + 1][j + 1] = '#';
				}
			}
		}
	}
	if (flag) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}