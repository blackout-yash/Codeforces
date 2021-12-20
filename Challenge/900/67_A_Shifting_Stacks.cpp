// A. Shifting Stacks
// Link - https://codeforces.com/problemset/problem/1486/A



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
		int arr[n], store = 0;
		bool flag = true;
		fora(i, 0, n) {
			cin >> arr[i];
			if (flag) {
				if (arr[i] + store >= i) {
					store = (arr[i] + store) - i;
				} else flag = false;
			}
		}

		if (flag) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}