// B. Squares
// Link - https://codeforces.com/problemset/problem/263/B



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

	int n, k;
	cin >> n >> k;
	int a[n];
	fora(i, 0, n) cin >> a[i];
	sort(a, a + n);

	if (k == 0) {
		if (a[n - 1] + 1 <= 1e9)cout << a[n - 1] + 1 << " " << a[n - 1] + 1 nline;
		else cout << "-1\n";
	} else if (n >= k) cout << a[n - k] << " " << a[n - k] nline;
	else cout << "-1\n";

	return 0;
}