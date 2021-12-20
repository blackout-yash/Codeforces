// A. Exciting Bets
// Link - https://codeforces.com/problemset/problem/1543/A



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
		int a, b;
		cin >> a >> b;
		int gcd = abs(a - b);
		if (gcd) {
			int rem = b % gcd;
			cout << gcd << " " << min(rem, gcd - rem) nline;
		} else cout << gcd << " "  << "0\n";
	}

	return 0;
}