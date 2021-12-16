// B. Make Product Equal One
// Link - https://codeforces.com/problemset/problem/1206/B



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

	int n, ans = 0, count = 0, zero = 0;
	cin >> n;
	int arr[n];
	fora(i, 0, n) {
		cin >> arr[i];
		if (arr[i] < 0) count++;
		else if (arr[i] == 0) zero++;
		if (arr[i] <= 0) ans += abs(arr[i] + 1);
		else ans += arr[i] - 1;
	}
	if (count & 1 && zero == 0) cout << ans + 2;
	else cout << ans;

	return 0;
}