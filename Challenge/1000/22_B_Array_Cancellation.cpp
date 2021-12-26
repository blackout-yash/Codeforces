// B. Array Cancellation
// Link - https://codeforces.com/problemset/problem/1405/B



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
		int n, x, sum = 0;
		cin >> n;
		fora(i, 0, n) {
			cin >> x;
			if (x >= 0) sum += x;
			else {
				if (abs(x) <= sum) sum += x;
				else sum = 0;
			}
		} cout << sum nline;
	}

	return 0;
}