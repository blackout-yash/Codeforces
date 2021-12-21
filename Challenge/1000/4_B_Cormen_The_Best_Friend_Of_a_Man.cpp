// B. Cormen — The Best Friend Of a Man
// Link - https://codeforces.com/problemset/problem/732/B



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
	int arr[n];
	fora(i, 0, n) cin >> arr[i];

	if (n == 1) cout << "0\n" << arr[0];
	else {
		int count = 0;
		fora(i, 0, n - 1) {
			int sum = arr[i] + arr[i + 1];
			if (sum < k) {
				count += (k - sum);
				arr[i + 1] += (k - sum);
			}
		} cout << count nline;
		fora(i, 0, n) cout << arr[i] << " ";
	}

	return 0;
}