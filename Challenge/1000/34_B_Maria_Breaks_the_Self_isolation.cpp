// B. Maria Breaks the Self-isolation
// Link - https://codeforces.com/problemset/problem/1358/B



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
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		vector <int> arr(n);
		fora(i, 0, n) cin >> arr[i];
		sort(arr.begin(), arr.end());

		bool flag = true;
		rfora(i, 0, n) {
			if (i + 1 >= arr[i]) {
				cout << i + 2 nline;
				flag = false;
				break;
			}
		}

		if (flag) cout << 1 nline;
	}

	return 0;
}