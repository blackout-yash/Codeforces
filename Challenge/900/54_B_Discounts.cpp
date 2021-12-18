// B. Discounts
// Link - https://codeforces.com/problemset/problem/1132/B



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

	int n, maximum = 0, sum = 0;
	cin >> n;
	int a[n];
	fora(i, 0, n) {
		cin >> a[i];
		sum += a[i];
		maximum = max(maximum, a[i]);
	} sort(a, a + n);

	int t;
	cin >> t;
	while (t--) {
		int q; cin >> q;
		cout << sum - a[n - q] nline;
	}

	return 0;
}