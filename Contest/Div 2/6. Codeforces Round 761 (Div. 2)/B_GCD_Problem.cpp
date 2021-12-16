// B. GCD Problem
// Link - https://codeforces.com/contest/1617/problem/B



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
		int n;
		cin >> n;
		if (n & 1) {
			if (((n - 1) / 2) & 1) cout << ((n - 1) / 2) - 2 << " " << ((n - 1) / 2) + 2 << " 1\n";
			else cout << ((n - 1) / 2) - 1 << " " << ((n - 1) / 2) + 1 << " 1\n";
		} else cout << (n - 1) / 2 << " " << ((n - 1) / 2) + 1 << " 1\n";

	}

	return 0;
}