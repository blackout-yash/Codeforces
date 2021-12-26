// B. Coloring Rectangles
// Link - https://codeforces.com/problemset/problem/1584/B



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
		int n, m;
		cin >> n >> m;
		int que1 = n / 3, rem1 = 0, que2 = m / 3, rem2 = 0;
		if (n % 3) {
			rem1 = m;
			int temp1 = que2 * (n % 3);
			if (m % 3) temp1 += (n % 3);
			rem1 = min(rem1, temp1);
		}

		if (m % 3) {
			rem2 = n;
			int temp2 = que1 * (m % 3);
			if (n % 3) temp2 += (m % 3);
			rem2 = min(rem2, temp2);
		}
		int min1 = (que1 * m) + rem1, min2 = (que2 * n) + rem2;
		if (min1 && min2) cout << min(min1, min2) nline;
		else if (min1) cout << min1 nline;
		else cout << min2 nline;
	}

	return 0;
}