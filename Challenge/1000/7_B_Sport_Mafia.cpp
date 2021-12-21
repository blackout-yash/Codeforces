// B. Sport Mafia
// Link - https://codeforces.com/problemset/problem/1195/B



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

	int n, k;
	cin >> n >> k;
	int num = 2 * (n + k);

	int x = 1, low, high;
	while (true) {
		int temp = x * x + 3 * x;
		if (temp > num) {
			low = x / 2; high = x;
			break;
		} x *= 2;
	}

	while (true) {
		int mid = low + (high - low) / 2;
		int temp = mid * mid + 3 * mid;
		if (temp == num) {
			cout << n - mid;
			break;
		} else if (temp > num) high = mid - 1;
		else low = mid + 1;
	}

	return 0;
}