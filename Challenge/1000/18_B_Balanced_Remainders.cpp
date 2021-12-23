// B. Balanced Remainders
// Link - https://codeforces.com/problemset/problem/1490/B



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

int solve(int &a, int &b, int &c, int n) {
	int count = 0, req = n - a, diff;
	if (n > a) {
		if (n < b) {
			diff = b - n;
			if (diff >= req) {
				a = n; b -= req;
				count += req;
			} else {
				a += diff; b = n;
				count += diff;
			}
		}

		if (n > a && n < c) {
			diff = c - n;
			if (diff >= req) {
				a = n; c -= req;
				count += (2 * req);
			} else {
				a += diff; c = n;
				count += (2 * diff);
			}
		}
	}
	return count;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int c1 = 0, c2 = 0, c3 = 0;
		fora(i, 0, n) {
			int x; cin >> x;
			if (x % 3 == 0) c1++;
			else if (x % 3 == 1) c2++;
			else c3++;
		}

		if (c1 == c2 && c1 == c3) cout << "0\n";
		else cout << solve(c1, c3, c2, long(n / 3)) + solve(c2, c1, c3, long(n / 3)) + solve(c3, c2, c1, long(n / 3)) nline;
	}

	return 0;
}