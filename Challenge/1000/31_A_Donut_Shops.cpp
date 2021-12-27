// A. Donut Shops
// Link - https://codeforces.com/problemset/problem/1373/A



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
		int a, b, c;
		cin >> a >> b >> c;

		double price1 = a, price2 = (double)c / b;
		if (price1 > price2) {
			if (a < c) cout << "1 " << b nline;
			else if (a == c) cout << "-1 2\n";
			else cout << "-1 1\n";
		} else cout << "1 -1\n";
	}

	return 0;
}