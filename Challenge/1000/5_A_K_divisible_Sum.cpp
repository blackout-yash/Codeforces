// A. K-divisible Sum
// Link - https://codeforces.com/problemset/problem/1476/A



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
		int n, k;
		cin >> n >> k;

		if (n > k) {
			if (n % k != 0) cout << "2\n";
			else cout << "1\n";
		} else {
			int que = k / n, rem = k % n;
			if (rem) cout << que + 1 nline;
			else cout << que nline;
		}
	}

	return 0;
}