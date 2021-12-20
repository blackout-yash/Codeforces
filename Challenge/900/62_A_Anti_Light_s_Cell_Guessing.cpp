// A. Anti Light's Cell Guessing
// Link - https://codeforces.com/problemset/problem/1610/A



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

	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (x == 1 && y == 1) cout << "0\n";
		else if (x == 1 || y == 1) cout << "1\n";
		else cout << "2\n";
	}

	return 0;
}