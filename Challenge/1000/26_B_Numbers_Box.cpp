// B. Numbers Box
// Link - https://codeforces.com/problemset/problem/1447/B



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

	int tt;
	cin >> tt;
	while (tt--) {
		int n, m, x, sum = 0, minimum = INT_MAX, count = 0;
		cin >> n >> m;
		fora(i, 0, n) {
			fora(j, 0, m) {
				cin >> x;
				sum += abs(x);
				minimum = min(minimum, abs(x));
				if (x < 0) count++;
			}
		}

		if (count & 1) cout << sum - (2 * minimum) nline;
		else cout << sum nline;
	}

	return 0;
}