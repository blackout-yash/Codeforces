// B. Candies Division
// Link - https://codeforces.com/problemset/problem/1283/B



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
		int n, k;
		cin >> n >> k;

		if (n >= k) {
			int rem = n % k;
			if (rem == 0) cout << (n / k)*k nline;
			else if (rem >= k / 2) cout << (n / k)*k +  k / 2 nline;
			else cout << (n / k)*k + rem nline;
		} else cout << min(n, k / 2) nline;
	}

	return 0;
}