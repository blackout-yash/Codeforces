// A. Number of Apartments
// Link - https://codeforces.com/problemset/problem/1430/A



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
		int n;
		cin >> n;
		if (n < 3 || n == 4) cout << "-1\n";
		else if (n % 3 == 0) cout << n / 3 << " 0 0\n";
		else if (n % 5 == 0) cout << "0 " << n / 5 << " 0\n";
		else if (n % 7 == 0) cout << "0 0 " << n / 7 nline;
		else if (n > 5) {
			int rem = n % 5;
			if (rem == 1) cout << "2 " << (n - 6) / 5 << " 0\n";
			else if (rem == 2) cout << "0 " << (n - 7) / 5 << " 1\n";
			else if (rem == 3) cout << "1 " << (n - 3) / 5 << " 0\n";
			else if (rem == 4) cout << "0 " << (n - 14) / 5 << " 2\n";
		}
	}

	return 0;
}