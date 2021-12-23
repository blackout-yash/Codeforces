// A. Contest Start
// Link - https://codeforces.com/contest/1539/problem/A



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
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n, x, tt;
		cin >> n >> x >> tt;
		if (x > tt) cout << "0\n";
		else if (x == tt) cout << n - 1 nline;
		else {
			int temp = tt / x;
			if (n >= temp) cout << (temp * (temp - 1)) / 2 + (n - temp)*temp nline;
			else cout << (n * (n - 1)) / 2 nline;
		}
	}

	return 0;
}