// A. Competitive Programmer
// Link - https://codeforces.com/problemset/problem/1266/A



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
		int n = size(s), zero = 0, even = 0, sum = 0;
		fora(i, 0, n) {
			int num = int32_t(s[i] - '0');
			if (!num) zero++;
			else if (!(num & 1)) even++;
			sum += num;
		}

		if (zero == n || (sum % 3 == 0 && zero && zero + even >= 2)) cout << "red\n";
		else cout << "cyan\n";
	}

	return 0;
}