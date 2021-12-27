// B. Assigning to Classes
// Link - https://codeforces.com/problemset/problem/1300/B



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
		vector <int> arr(2 * n);
		fora(i, 0, 2 * n) cin >> arr[i];
		sort(arr.begin(), arr.end());
		cout << arr[n] - arr[n - 1] nline;
	}

	return 0;
}